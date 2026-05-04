//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//comparison.cpp
#include "includes.h"
#include "las_vegas.h"
#include "rabin_karp.h"

// Displays comparison menu and runs performance comparison between Quick Sort and Rabin-Karp algorithms.
// Allows user to specify the number of iterations and test data for comparing algorithm performance.
// Measures execution time and displays average timing and faster algorithm.
// Parameters: none
// Returns: void (displays results to console)
void comparison_menu()
{
    int k;
    cout << "Enter number of iterations for comparison (k): ";
    string k_input;
    getline(cin, k_input);
    while (k_input.empty() || !all_of(k_input.begin(), k_input.end(), ::isdigit) || stoi(k_input) <= 0) {
        cout << "Invalid input. Enter a positive integer: ";
        getline(cin, k_input);
    }
    k = stoi(k_input);

    while (true) {
        cout << "\n========== Comparison Options ==========" << endl;
        cout << "1. Compare Quick Sort vs Rabin-Karp" << endl;
        cout << "2. Return to Main Menu" << endl;
        cout << "========================================" << endl;
        cout << "Choose an option (1 or 2): ";
        string choice;
        getline(cin, choice);

        while (choice != "1" && choice != "2") {
            cout << "Invalid choice. Enter 1 or 2: ";
            getline(cin, choice);
        }

        if (choice == "2") {
            break;
        }

        if (choice == "1") {
            string test_input;
            cout << "\nEnter test data (letters and spaces): ";
            getline(cin, test_input);
            while (test_input.empty()) {
                cout << "Input cannot be empty. Please try again: ";
                getline(cin, test_input);
            }

            cout << "\n========== Running " << k << " Iterations ==========" << endl;

            // Quick Sort Comparison
            cout << "\n--- Quick Sort (Randomized) ---" << endl;
            long long total_quicksort_time = 0;
            string filtered = normalize_string(test_input, false);
            if (!filtered.empty()) {
                for (int i = 0; i < k; i++) {
                    auto start = high_resolution_clock::now();
                    string sorted = random_quick_sort(filtered);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    total_quicksort_time += duration.count();
                }
                long long avg_quicksort = total_quicksort_time / k;
                cout << "Total time for " << k << " iterations: " << total_quicksort_time << " microseconds" << endl;
                cout << "Average time per iteration: " << avg_quicksort << " microseconds" << endl;
            } else {
                cout << "No valid characters to sort." << endl;
            }

            // Rabin-Karp Comparison
            cout << "\n--- Rabin-Karp (String Matching) ---" << endl;
            cout << "Enter pattern to search for: ";
            string pattern;
            getline(cin, pattern);
            while (pattern.empty()) {
                cout << "Pattern cannot be empty. Please try again: ";
                getline(cin, pattern);
            }

            long long total_rk_time = 0;
            string filtered_text = normalize_string_rk(test_input, false);
            string filtered_pattern = normalize_string_rk(pattern, false);

            if (!filtered_pattern.empty() && !filtered_text.empty()) {
                for (int i = 0; i < k; i++) {
                    auto start = high_resolution_clock::now();
                    vector<int> matches = rabin_karp_search(filtered_text, filtered_pattern);
                    auto stop = high_resolution_clock::now();
                    auto duration = duration_cast<microseconds>(stop - start);
                    total_rk_time += duration.count();
                }
                long long avg_rk = total_rk_time / k;
                cout << "Total time for " << k << " iterations: " << total_rk_time << " microseconds" << endl;
                cout << "Average time per iteration: " << avg_rk << " microseconds" << endl;
            } else {
                cout << "No valid characters to search." << endl;
            }

            // Comparison Summary
            if (!filtered.empty() && !filtered_pattern.empty() && !filtered_text.empty()) {
                cout << "\n========== Summary ==========" << endl;
                long long avg_quicksort = total_quicksort_time / k;
                long long avg_rk = total_rk_time / k;
                cout << "Quick Sort Average: " << avg_quicksort << " microseconds" << endl;
                cout << "Rabin-Karp Average: " << avg_rk << " microseconds" << endl;
                if (avg_quicksort < avg_rk) {
                    cout << "Quick Sort is faster by " << (avg_rk - avg_quicksort) << " microseconds" << endl;
                } else {
                    cout << "Rabin-Karp is faster by " << (avg_quicksort - avg_rk) << " microseconds" << endl;
                }
                cout << "=============================" << endl;
            }

            cout << "\nWould you like to run another comparison? (y/n): ";
            string again;
            getline(cin, again);
            if (again.empty() || tolower(again[0]) != 'y') {
                break;
            }
        }
    }
}
