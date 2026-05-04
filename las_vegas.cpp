//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//las_vegas.cpp
// AI Usage: ai was used in the generation of comments about function definitions and their parameters.

//This file contains implementations of Las Vegas algorithms:
//- Random Quick Sort for string sorting
//- Las Vegas Primality Testing (randomised trial division)
//Both algorithms are guaranteed to be correct but have variable runtime.

#include "includes.h"

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
// Parameters: n - the number to test, a - the witness value
// Returns: true if n is likely prime for this witness, false if n is composite
bool miller_rabin_witness(long long n, long long a) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

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


///////////////////////////////////////////////////////////////////PRESENTATION EXAMPLE 2 !!!
// Uses randomised trial division: checks divisors in random order.
// Always returns the correct answer, but runtime varies randomly.
// Parameters: n - the number to test for primality
// Returns: true if n is prime, false if n is composite
bool las_vegas_primality(long long n) {
	//checks if n is less than or equal to 1, if so returns false (not prime)
    if (n <= 1) return false;
	//checks if n is equal to 2 or 3, if so returns true (is prime)
    if (n == 2 || n == 3) return true;
	//checks if n is even, if so returns false (not prime)
    if (n % 2 == 0) return false;

	//any composite number must have a divisor less than or equal to its square root
    long long limit = sqrt(n);
	//generates a list of odd divisors from 3 to limit
	//amortized O(1) time complexity for generating the list of divisors, but O(√n) space complexity for storing them
    vector<long long> divisors;
	//generates odd divisors from 3 to limit it, 3 because even numbers are not prime (except 2) and we already checked for evenness above
    for (long long d = 3; d <= limit; d += 2) {
        divisors.push_back(d);
    }
	//AI Usage: ai suggested this line 132 because before i was using rand() % divisors.size() to randomly select a divisor
    // but that would not guarantee that all divisors are checked. By shuffling the list, we ensure that all divisors are checked in random order.
	//randomly shuffles the list of divisors to ensure random order of checking
    shuffle(divisors.begin(), divisors.end(), gen);

	//checks each divisor in the shuffled list to see if it divides n
    for (long long d : divisors) {
		//if n is divisible by d, then n is composite (not prime)
        if (n % d == 0) {
            return false;
        }
    }
	//if no divisors divide n, then n is prime
    return true;
}

////////////////////////////////////////////////////////////////////////////PRESENTATION EXAMPLE 1 !!!
// Sorts a string using random quick sort with a randomly selected pivot.
// Parameters: s - the string to sort
// Returns: the sorted string
string random_quick_sort(string s)
{
	// if the string has 0 or 1 character, it is already sorted
    if (s.size() <= 1)
    {
        return s;
    }

	// select a random pivot index 
	//issue example: when i added this, rand() was not seeded - fix, line 15 random device{}() to seed the mt19937 generator
    int pivot_index = rand() % s.size();
    //get the character of the pivot
    char pivot = s[pivot_index];

	// create three strings to hold characters less than, greater than, and equal to the pivot
    string left = "";
    string right = "";
    string middle = "";

	// partition the string into left, right, and middle based on the pivot
    for (int i = 0; i < (int)s.size(); i++)
    {
		//if the character is less than the pivot, add it to the left string
        if (s[i] < pivot)
        {
            left += s[i];
        }
		//if the character is greater than the pivot, add it to the right string
        else if (s[i] > pivot)
        {
            right += s[i];
        }
		// if the character is equal to the pivot, add it to the middle string
        else
        {
            middle += s[i];
        }
    }
	// recursively sort the left and right strings and concatenate them with the middle string
    return random_quick_sort(left) + middle + random_quick_sort(right);
}

// Prompts the user to enter a valid string and validates the input.
// Parameters: none
// Returns: a non-empty string containing at least one letter
string get_valid_string_input()
{
    string input;
    cout << "Enter a string to sort using quick sort (letters and spaces only, not empty): ";
    getline(cin, input);
    while (input.empty() || !has_letter(input)) {
        if (input.empty())
            cout << "Input cannot be empty. Please try again: ";
        else
            cout << "Input must contain at least one letter. Please try again: ";
        getline(cin, input);
    }
    return input;
}

// Normalizes a string by converting to lowercase and filtering characters.
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