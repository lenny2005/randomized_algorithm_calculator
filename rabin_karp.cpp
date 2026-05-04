//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//rabin_karp.cpp
#include "includes.h"

const long long BASE = 256;
const long long MOD = 101;

string normalize_string_rk(const string& input, bool keep_spaces = false)
{
    string result;
    for (char c : input) {
        if (isalpha(static_cast<unsigned char>(c))) {
            result += c;
        } else if (keep_spaces && c == ' ') {
            result += ' ';
        }
    }
    return result;
}

vector<int> rabin_karp_search(const string& text, const string& pattern)
{
    vector<int> matches;
    size_t n = text.size();
    size_t m = pattern.size();

    if (m > n || m == 0) {
        return matches;
    }

    long long pattern_hash = 0;
    long long text_hash = 0;
    long long h = 1;

    // Calculate h = BASE^(m-1) % MOD
    for (size_t i = 0; i < m - 1; i++) {
        h = (h * BASE) % MOD;
    }

    // Calculate hash for pattern and first window of text
    for (size_t i = 0; i < m; i++) {
        pattern_hash = (pattern_hash * BASE + pattern[i]) % MOD;
        text_hash = (text_hash * BASE + text[i]) % MOD;
    }

    // Slide the pattern over text
    for (size_t i = 0; i <= n - m; i++) {
        // Check if hashes match
        if (pattern_hash == text_hash) {
            // Verify match (Monte Carlo: verify to ensure correctness)
            bool match = true;
            for (size_t j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                matches.push_back(static_cast<int>(i));
            }
        }

        // Calculate hash for next window
        if (i < n - m) {
            text_hash = (BASE * (text_hash - text[i] * h) + text[i + m]) % MOD;
            if (text_hash < 0) {
                text_hash = (text_hash + MOD);
            }
        }
    }

    return matches;
}

string search_pattern(const string& text, const string& pattern)
{
    string filtered_text = normalize_string_rk(text, false);
    string filtered_pattern = normalize_string_rk(pattern, false);

    if (filtered_pattern.empty()) {
        return "Pattern must contain at least one letter.";
    }
    if (filtered_text.empty()) {
        return "Text must contain at least one letter.";
    }

    auto start = high_resolution_clock::now();
    vector<int> matches = rabin_karp_search(filtered_text, filtered_pattern);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    string result = "Pattern: " + filtered_pattern + "\n";
    result += "Text: " + filtered_text + "\n";
    if (matches.empty()) {
        result += "No matches found.\n";
    } else {
        result += "Matches found at positions: ";
        for (int pos : matches) {
            result += to_string(pos) + " ";
        }
        result += "\n";
        result += "Total matches: " + to_string(matches.size()) + "\n";
    }
    result += "Time taken: " + to_string(duration.count()) + " microseconds";

    return result;
}

string get_valid_pattern_input()
{
    string input;
    cout << "Enter a pattern to search for (letters only, not empty): ";
    getline(cin, input);
    while (input.empty()) {
        cout << "Input cannot be empty. Please try again: ";
        getline(cin, input);
    }
    return input;
}

string get_valid_text_input()
{
    string input;
    cout << "Enter text to search in (letters and spaces only, not empty): ";
    getline(cin, input);
    while (input.empty()) {
        cout << "Input cannot be empty. Please try again: ";
        getline(cin, input);
    }
    return input;
}

