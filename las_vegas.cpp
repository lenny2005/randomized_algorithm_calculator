//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//las_vegas.cpp
//This file contains implementations of Las Vegas algorithms:
//- Random Quick Sort for string sorting
//- Las Vegas Primality Testing (Miller-Rabin)
//Both algorithms are guaranteed to be correct but have variable runtime.

#include "includes.h"

// ========== Primality Testing Functions ==========

mt19937 gen(random_device{}());

// Computes modular exponentiation: (base^exp) % mod using binary exponentiation.
// Parameters: base - the base number, exp - the exponent, mod - the modulus
// Returns: The result of (base^exp) % mod
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Performs Miller-Rabin primality test for a given witness.
// Determines if n is composite by testing with witness a.
// Parameters: n - the number to test, a - the witness value
// Returns: true if n is likely prime for this witness, false if n is composite
bool miller_rabin_witness(long long n, long long a) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    // Write n-1 as 2^r * d
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    long long x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) return true;

    for (int i = 0; i < r - 1; i++) {
        x = (x * x) % n;
        if (x == n - 1) return true;
    }
    return false;
}

// Displays step-by-step breakdown of Miller-Rabin primality test for a given number.
// Shows each round of witness testing and indicates whether the number is prime or composite.
// Parameters: n - the number to test
// Returns: void (prints results to console)
void show_primality_steps(long long n) {
    if (n <= 1 || n % 2 == 0) {
        cout << "  No rounds needed (caught by early check)." << endl;
        return;
    }

    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    cout << "  n-1 = 2^" << r << " * " << d << endl;

    uniform_int_distribution<long long> dis(2, n - 2);

    int max_attempts = 100;
    for (int attempt = 0; attempt < max_attempts; attempt++) {
        long long a = dis(gen);
        long long x = mod_pow(a, d, n);

        cout << "  Round " << (attempt + 1) << ": a = " << a
            << " | x = a^d mod n = " << x;

        if (x == 1 || x == n - 1) {
            cout << " | PASS (likely prime for this witness)" << endl;
            continue;
        }

        bool found = false;
        for (int i = 0; i < r - 1; i++) {
            x = (x * x) % n;
            if (x == n - 1) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << " | FAIL -> composite witness found" << endl;
            return;
        }

        cout << " | PASS (x reached n-1 during squaring)" << endl;
    }

    cout << "  No composite witness found after " << max_attempts
        << " rounds -> declared PRIME" << endl;
}

// Las Vegas primality test - guaranteed to be correct with variable runtime.
// Tests whether a number is prime using multiple random witnesses.
// Always returns the correct answer but runtime varies based on random witness selection.
// Parameters: n - the number to test for primality
// Returns: true if n is prime, false if n is composite
bool las_vegas_primality(long long n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    uniform_int_distribution<long long> dis(2, n - 2);

    int max_attempts = 100;
    for (int attempt = 0; attempt < max_attempts; attempt++) {
        long long a = dis(gen);
        if (!miller_rabin_witness(n, a)) {
            return false;
        }
    }
    return true;
}

// ========== Quick Sort Functions ==========

// Performs random quick sort on a string using a randomly selected pivot.
// Partitions the string into three parts (less than, equal to, greater than pivot)
// and recursively sorts each partition.
// Parameters: s - the string to sort
// Returns: the sorted string
string random_quick_sort(string s)
{
    if (s.size() <= 1)
    {
        return s;
    }

    int pivot_index = rand() % s.size();  // fixed: includes last index
    char pivot = s[pivot_index];

    string left = "";
    string right = "";
    string middle = "";

    for (int i = 0; i < (int)s.size(); i++)  // fixed: signed/unsigned mismatch
    {
        if (s[i] < pivot)
        {
            left += s[i];
        }
        else if (s[i] > pivot)
        {
            right += s[i];
        }
        else
        {
            middle += s[i];
        }
    }
    return random_quick_sort(left) + middle + random_quick_sort(right);
}

// Prompts the user to enter a valid string and validates the input.
// Ensures the input is not empty before returning.
// Parameters: none
// Returns: a non-empty string entered by the user
string get_valid_string_input()
{
    string input;
    cout << "Enter a string to sort using quick sort (letters and spaces only, not empty): ";
    getline(cin, input);
    while (input.empty()) {
        cout << "Input cannot be empty. Please try again: ";
        getline(cin, input);
    }
    return input;
}

// Normalizes a string by converting to lowercase and filtering characters.
// Removes non-alphabetic characters and optionally preserves spaces.
// Parameters: input - the string to normalize, keep_spaces - whether to preserve spaces
// Returns: the normalized string
string normalize_string(const string& input, bool keep_spaces)
{
    string result;
    for (char c : input) {
        if (isalpha(static_cast<unsigned char>(c))) {
            result += tolower(static_cast<unsigned char>(c));
        }
        else if (keep_spaces && c == ' ') {
            result += ' ';
        }
    }
    return result;
}

// Sorts the entire input string as a single continuous string without spaces.
// Filters to keep only letters, removes all spaces, and applies quick sort.
// Measures and reports the execution time in microseconds.
// Parameters: input - the string to sort
// Returns: a formatted string with the sorted result and execution time
string sort_as_one_string(const string& input) {
    string filtered = normalize_string(input, false);
    if (filtered.empty()) {
        return "Input must contain at least one letter.";
    }
    auto start = high_resolution_clock::now();
    string sorted = random_quick_sort(filtered);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return "Sorted as one string (all letters, no spaces):\n" + sorted + "\nTime taken: " + to_string(duration.count()) + " microseconds";
}

// Sorts each word in the input string separately while preserving word boundaries.
// Applies quick sort to the letters in each word individually.
// Measures and reports the execution time in microseconds.
// Parameters: input - the string containing words to sort
// Returns: a formatted string with each word sorted and execution time
string sort_each_word(const string& input) {
    istringstream iss(input);
    string word, result;
    auto start = high_resolution_clock::now();
    while (iss >> word) {
        string word_filtered = normalize_string(word, false);
        if (!word_filtered.empty()) {
            result += random_quick_sort(word_filtered) + " ";
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    if (!result.empty()) result.pop_back();
    return "Sorted as separate words (letters only in each word):\n" + result + "\nTime taken: " + to_string(duration.count()) + " microseconds";
}

// Handles quick sort operation with user selection of sorting mode.
// If input contains spaces, prompts user to choose between sorting as one string
// or sorting each word separately. Displays the sorted result with timing.
// Parameters: input - the string to sort
// Returns: void (displays results to console)
void do_quick_sort(const string& input)
{
    bool has_space = input.find(' ') != string::npos;
    if (has_space) {
        cout << "Multiple words detected. Choose sorting mode:\n";
        cout << "1. Sort as one string (all letters, no spaces)\n";
        cout << "2. Sort each word separately\n";
        cout << "Enter 1 or 2: ";
        string choice;
        getline(cin, choice);
        while (choice != "1" && choice != "2") {
            cout << "Invalid choice. Enter 1 or 2: ";
            getline(cin, choice);
        }
        if (choice == "1") {
            cout << sort_as_one_string(input) << endl;
        }
        else {
            cout << sort_each_word(input) << endl;
        }
    }
    else {
        cout << sort_as_one_string(input) << endl;
    }
}