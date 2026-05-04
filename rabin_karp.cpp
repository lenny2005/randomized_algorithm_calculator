//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//rabin_karp.cpp
// AI Usage: ai was used in the generation of comments about function definitions and their parameters.

//This file contains the implementation of the Monte Carlo Rabin-Karp string matching algorithm.
//Uses a rolling hash without character verification. May produce false positives.

#include "includes.h"

const long long BASE = 256;
const long long MOD = 101;


// Normalizes a string by filtering out non-alphabetic characters.
// Parameters: input - the string to normalize, keep_spaces - whether to preserve spaces
// Returns: the normalized string containing only letters (and spaces if requested)
string normalize_string_rk(const string& input, bool keep_spaces)
{
    string result;
    for (char c : input) {
        if (isalpha(static_cast<unsigned char>(c))) {
            result += c;
        }
        else if (keep_spaces && c == ' ') {
            result += ' ';
        }
    }
    return result;
}

// Searches for all occurrences of a pattern in text using Monte Carlo Rabin-Karp.
// Parameters: text - the string to search in, pattern - the string to search for
// Returns: a vector of starting positions where the pattern hash matches (may include false positives)
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

    for (size_t i = 0; i < m - 1; i++) {
        h = (h * BASE) % MOD;
    }

    for (size_t i = 0; i < m; i++) {
        pattern_hash = (pattern_hash * BASE + pattern[i]) % MOD;
        text_hash = (text_hash * BASE + text[i]) % MOD;
    }

    for (size_t i = 0; i <= n - m; i++) {
        if (pattern_hash == text_hash) {
            matches.push_back(static_cast<int>(i));
        }

        if (i < n - m) {
            text_hash = (BASE * (text_hash - text[i] * h) + text[i + m]) % MOD;
            if (text_hash < 0) {
                text_hash = (text_hash + MOD);
            }
        }
    }

    return matches;
}

// Wrapper function for Monte Carlo search – normalises inputs and reports results.
// Parameters: text - the text to search in, pattern - the pattern to search for
// Returns: a formatted string showing pattern, text, match positions, and time taken
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
    }
    else {
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

// Prompts the user to enter a valid pattern string and validates the input.
// Parameters: none
// Returns: a non-empty string containing at least one letter
string get_valid_pattern_input()
{
    string input;
    cout << "Enter a pattern to search for (letters only, not empty): ";
    getline(cin, input);
    while (input.empty() || !has_letter(input)) {
        if (input.empty())
            cout << "Pattern cannot be empty. Please try again: ";
        else
            cout << "Pattern must contain at least one letter. Please try again: ";
        getline(cin, input);
    }
    return input;
}

// Prompts the user to enter a valid text string and validates the input.
// Parameters: none
// Returns: a non-empty string containing at least one letter
string get_valid_text_input()
{
    string input;
    cout << "Enter text to search in (letters and spaces only, not empty): ";
    getline(cin, input);
    while (input.empty() || !has_letter(input)) {
        if (input.empty())
            cout << "Text cannot be empty. Please try again: ";
        else
            cout << "Text must contain at least one letter. Please try again: ";
        getline(cin, input);
    }
    return input;
}