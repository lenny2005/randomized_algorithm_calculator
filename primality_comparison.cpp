//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//primality_comparison.cpp
// AI Usage: ai was used in the generation of comments about function definitions and their parameters.

#include "includes.h"
#include "las_vegas.h"
#include "monte_carlo.h"

extern mt19937 gen;
// Helper to check if a string is a valid positive integer within long long range.
// Parameters: s - the string to validate
// Returns: true if s represents a positive integer that fits in long long, false otherwise
bool is_valid_positive_integer(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    if (s.length() > 18) return false;
    long long val = stoll(s);
    return val > 0;
}
// Prompts user for number of test cases and number range, then generates random numbers.
// Runs both Las Vegas and Monte Carlo primality tests on the same set and compares results.
// Parameters: none
// Returns: void (displays comparison results to console)
void primality_comparison_menu()
{
    while (true) {
        cout << "(1) See algorithm steps (2) Compare Las Vegas vs Monte Carlo Primality (3) Return to Main Menu : " << endl;
        string choice;
        getline(cin, choice);

        while (choice != "1" && choice != "2" && choice != "3") {
            cout << "Invalid choice. Enter 1, 2, or 3: ";
            getline(cin, choice);
        }

        if (choice == "3") {
            break;
        }

        if (choice == "1") {
            cout << "\nAlgorithm Steps" << endl;
            cout << "\nLas Vegas Primality Testing (Randomised Trial Division)" << endl;
            cout << "Steps:" << endl;
            cout << "  1. If n <= 1, return false (composite). If n == 2 or 3, return true (prime)." << endl;
            cout << "  2. If n is even, return false (composite)." << endl;
            cout << "  3. Generate a list of all odd numbers from 3 up to √n (potential divisors)." << endl;
            cout << "  4. Randomly shuffle the list (random order of checking)." << endl;
            cout << "  5. For each divisor d in the shuffled list:" << endl;
            cout << "       - If n % d == 0, return false (composite) immediately." << endl;
            cout << "  6. If no divisor divides n, return true (prime)." << endl;
            cout << "\nMonte Carlo Primality Testing (Miller-Rabin)" << endl;
            print_monte_carlo_primality_steps();
            continue;
        }

        // choice == "2" – run comparison
        int k;
        cout << "Enter number of test numbers to generate (k): ";
        string k_input;
        getline(cin, k_input);
        while (!is_valid_positive_integer(k_input) || stoll(k_input) > 1000000) {
            cout << "Invalid input. Enter a positive integer (1 - 1,000,000): ";
            getline(cin, k_input);
        }
        k = stoi(k_input);

        cout << "Enter range for random numbers (e.g., 100-10000): ";
        string range_input;
        getline(cin, range_input);

        long long min_range = 100, max_range = 10000;
        bool valid_range = false;

        while (!valid_range) {
            size_t dash_pos = range_input.find('-');
            if (dash_pos != string::npos && dash_pos != 0 && dash_pos != range_input.length() - 1) {
                try {
                    string min_str = range_input.substr(0, dash_pos);
                    string max_str = range_input.substr(dash_pos + 1);
                    if (is_valid_positive_integer(min_str) && is_valid_positive_integer(max_str)) {
                        min_range = stoll(min_str);
                        max_range = stoll(max_str);
                        if (min_range >= 2 && max_range > min_range && max_range - min_range <= 10000000) {
                            valid_range = true;
                        }
                        else {
                            cout << "Min must be >= 2, max must be > min, and range width <= 10 million. Try again: ";
                            getline(cin, range_input);
                        }
                    }
                    else {
                        cout << "Invalid format. Use positive integers like 100-10000: ";
                        getline(cin, range_input);
                    }
                }
                catch (...) {
                    cout << "Invalid format. Use format like 100-10000: ";
                    getline(cin, range_input);
                }
            }
            else {
                cout << "Invalid format. Use format like 100-10000: ";
                getline(cin, range_input);
            }
        }

        uniform_int_distribution<long long> dis(min_range, max_range);
        vector<long long> test_numbers(k);
        for (int i = 0; i < k; i++) {
            test_numbers[i] = dis(gen);
        }

        cout << "\nRunning " << k << " Tests" << endl;
        cout << "Testing numbers: ";
        for (int i = 0; i < k; i++) {
            cout << test_numbers[i];
            if (i < k - 1) cout << ", ";
        }
        cout << endl;

        cout << "\nLas Vegas Primality Testing" << endl;
        long long total_lv_time = 0;
        int lv_primes = 0;
        for (int i = 0; i < k; i++) {
            long long n = test_numbers[i];
            auto start = high_resolution_clock::now();
            bool is_prime = las_vegas_primality(n);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            total_lv_time += duration.count();
            if (is_prime) lv_primes++;
        }
        long long avg_lv = total_lv_time / k;
        cout << "Total time for " << k << " tests: " << total_lv_time << " microseconds" << endl;
        cout << "Average time per test: " << avg_lv << " microseconds" << endl;
        cout << "Primes found: " << lv_primes << endl;

        cout << "\nMonte Carlo Primality Testing" << endl;
        long long total_mc_time = 0;
        int mc_primes = 0;
        for (int i = 0; i < k; i++) {
            long long n = test_numbers[i];
            auto start = high_resolution_clock::now();
            bool is_prime = monte_carlo_primality(n, 20);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            total_mc_time += duration.count();
            if (is_prime) mc_primes++;
        }
        long long avg_mc = total_mc_time / k;
        cout << "Total time for " << k << " tests: " << total_mc_time << " microseconds" << endl;
        cout << "Average time per test: " << avg_mc << " microseconds" << endl;
        cout << "Primes found: " << mc_primes << endl;

        cout << "\nSummary" << endl;
        cout << "Las Vegas Average:      " << avg_lv << " microseconds" << endl;
        cout << "Monte Carlo Average:    " << avg_mc << " microseconds" << endl;
        cout << "Las Vegas Primes Found: " << lv_primes << endl;
        cout << "Monte Carlo Primes Found: " << mc_primes << endl;
        if (lv_primes == mc_primes) {
            cout << "Both algorithms agree on prime count." << endl;
        }
        else {
            cout << "WARNING: Algorithms disagree on prime count!" << endl;
        }
        if (avg_lv < avg_mc) {
            cout << "Las Vegas is faster by " << (avg_mc - avg_lv) << " microseconds" << endl;
        }
        else {
            cout << "Monte Carlo is faster by " << (avg_lv - avg_mc) << " microseconds" << endl;
        }

        cout << "\nWould you like to run another comparison? (y/n): ";
        string again;
        getline(cin, again);
        while (!again.empty() && tolower(again[0]) != 'y' && tolower(again[0]) != 'n') {
            cout << "Invalid input. Enter y or n: ";
            getline(cin, again);
        }
        if (again.empty() || tolower(again[0]) != 'y') {
            break;
        }
    }
}