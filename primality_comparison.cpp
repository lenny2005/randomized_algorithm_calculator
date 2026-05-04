//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//primality_comparison.cpp
#include "includes.h"
#include "las_vegas.h"
#include "monte_carlo.h"

extern mt19937 gen;
void primality_comparison_menu()
{
    int k;
    cout << "Enter number of test numbers to generate (k): ";
    string k_input;
    getline(cin, k_input);
    while (k_input.empty() || !all_of(k_input.begin(), k_input.end(), ::isdigit) || stoi(k_input) <= 0) {
        cout << "Invalid input. Enter a positive integer: ";
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
        if (dash_pos != string::npos && dash_pos != 0) {
            try {
                min_range = stoll(range_input.substr(0, dash_pos));
                max_range = stoll(range_input.substr(dash_pos + 1));
                if (min_range >= 2 && max_range > min_range) {
                    valid_range = true;
                }
                else {
                    cout << "Min must be >= 2 and max must be greater than min. Try again: ";
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

    // Generate all numbers ONCE before any testing
    mt19937 gen(random_device{}());
    uniform_int_distribution<long long> dis(min_range, max_range);
    vector<long long> test_numbers(k);
    for (int i = 0; i < k; i++) {
        test_numbers[i] = dis(gen);
    }

    cout << "\n========== Running " << k << " Tests ==========" << endl;

    // Print the numbers being tested so both runs are transparent
    cout << "Testing numbers: ";
    for (int i = 0; i < k; i++) {
        cout << test_numbers[i];
        if (i < k - 1) cout << ", ";
    }
    cout << endl;

    // Las Vegas Testing
    cout << "\n--- Las Vegas Primality Testing ---" << endl;
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

    // Monte Carlo Testing
    cout << "\n--- Monte Carlo Primality Testing ---" << endl;
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

    // Comparison Summary
    cout << "\n========== Summary ==========" << endl;
    cout << "Las Vegas Average: " << avg_lv << " microseconds" << endl;
    cout << "Monte Carlo Average: " << avg_mc << " microseconds" << endl;
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
    cout << "=============================" << endl;
}
