//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//menu.cpp
// AI Usage: ai was used in the generation of comments about function definitions and their parameters.

#include "includes.h"
#include "las_vegas.h"
#include "rabin_karp.h"
#include "comparison.h"
#include "monte_carlo.h"
#include "primality_comparison.h"
using namespace std;

// Displays the time and space complexity analysis of Random Quick Sort algorithm.
// Parameters: none
// Returns: void (prints to console)
void print_quicksort_complexity() {
    cout << "\n[Quick Sort - Las Vegas]" << endl;
    cout << "  Time:  O(n log n) avg | O(n^2) worst (rare)" << endl;
    cout << "  Space: O(log n) recursion stack" << endl;
}

// Displays a summary and use-case recommendation for Quick Sort algorithm.
// Parameters: none
// Returns: void (prints to console)
void print_quicksort_summary() {
    cout << "  -> Use Quick Sort when correctness is required and input is large." << endl;
}

// Displays detailed step-by-step explanation of Random Quick Sort algorithm.
// Parameters: none
// Returns: void (prints to console)
void print_quicksort_steps() {
    cout << "\nSteps for Random Quick Sort (Las Vegas):" << endl;
    cout << "  1. If the array has 0 or 1 element, it is already sorted – return." << endl;
    cout << "  2. Pick a random pivot element from the current subarray." << endl;
    cout << "  3. Partition: move all elements less than the pivot to its left," << endl;
    cout << "     and all elements greater than the pivot to its right." << endl;
    cout << "  4. The pivot is now in its final sorted position." << endl;
    cout << "  5. Recursively apply steps 1-4 to the left subarray (elements < pivot)." << endl;
    cout << "  6. Recursively apply steps 1-4 to the right subarray (elements > pivot)." << endl;
    cout << "  7. The array is sorted when all recursive calls complete." << endl;
    cout << "\nComparisons performed:" << endl;
    cout << "  - Each element is compared to the pivot during partitioning." << endl;
    cout << "  - Randomising the pivot avoids worst-case O(n^2) on sorted input." << endl;
}

// Displays the time and space complexity analysis of Las Vegas Primality Testing (randomised trial division).
// Parameters: none
// Returns: void (prints to console)
void print_lv_primality_complexity() {
    cout << "\n[Las Vegas Primality - Randomised Trial Division]" << endl;
    cout << "  Time:  O(?n) worst-case (prime) | O(1) best-case (small divisor found early)" << endl;
    cout << "  Space: O(?n) for divisor list" << endl;
}

// Displays a summary and use-case recommendation for Las Vegas Primality Testing.
// Parameters: none
// Returns: void (prints to console)
void print_lv_primality_summary() {
    cout << "\nSummary: Las Vegas Primality (Randomised Trial Division)" << endl;
    cout << "- Always correct, but runtime varies randomly depending on order of divisors." << endl;
    cout << "- For composite numbers, may finish quickly if a small divisor is found early." << endl;
    cout << "- For primes, must test all odd numbers up to ?n." << endl;
    cout << "- Used when guaranteed correctness is required and n is small to moderate." << endl;
}

// Displays the time and space complexity analysis of Rabin-Karp (Monte Carlo) string matching.
// Parameters: none
// Returns: void (prints to console)
void print_rabin_karp_complexity() {
    cout << "\n[Rabin-Karp - Monte Carlo]" << endl;
    cout << "  Time:  O(n+m) expected | O(nm) worst (many hash collisions)" << endl;
    cout << "  Space: O(1)" << endl;
}

// Displays a summary and use-case recommendation for Monte Carlo Rabin-Karp.
// Parameters: none
// Returns: void (prints to console)
void print_rabin_karp_summary() {
    cout << "  -> Use Monte Carlo Rabin-Karp for fast pattern search when a small" << endl;
    cout << "     probability of false positives is acceptable." << endl;
}

// Displays detailed step-by-step explanation of Monte Carlo Rabin-Karp (no verification).
// Parameters: none
// Returns: void (prints to console)
void print_rabin_karp_steps() {
    cout << "\nSteps for Rabin-Karp String Matching (Monte Carlo – no verification):" << endl;
    cout << "  1. Compute a rolling hash of the pattern (length m)." << endl;
    cout << "  2. Compute the hash of the first m characters of the text." << endl;
    cout << "  3. Slide a window of size m across the text, one character at a time:" << endl;
    cout << "       a. If the window hash matches the pattern hash, record this position as a match." << endl;
    cout << "            - No character-by-character verification is performed." << endl;
    cout << "            - False positives may occur due to hash collisions." << endl;
    cout << "       b. Remove the leftmost character from the hash (subtract its contribution)." << endl;
    cout << "       c. Add the next character to the hash (rolling update)." << endl;
    cout << "  4. Report all positions where the hash matched." << endl;
    cout << "\nComparisons performed:" << endl;
    cout << "  - Hash comparison at each window position: O(1) per step." << endl;
    cout << "  - No character comparisons after a hash match (pure Monte Carlo)." << endl;
}

// Displays the time and space complexity analysis of Monte Carlo Primality Testing (Miller-Rabin).
// Parameters: none
// Returns: void (prints to console)
void print_mc_primality_complexity() {
    cout << "\n[Monte Carlo Primality - Miller-Rabin]" << endl;
    cout << "  Time:  O(k log^2 n) | k = fixed rounds (e.g., 20)" << endl;
    cout << "  Space: O(1)" << endl;
}

// Displays a summary and use-case recommendation for Monte Carlo Primality Testing.
// Parameters: none
// Returns: void (prints to console)
void print_mc_primality_summary() {
    cout << "  -> Use Monte Carlo when speed matters more than absolute certainty." << endl;
    cout << "     Error probability ? 4^(-k) (e.g., for k=20, error < 2^(-40))." << endl;
}

// Displays detailed step-by-step explanation of Monte Carlo Primality Testing (Miller-Rabin).
// Parameters: none
// Returns: void (prints to console)
void print_monte_carlo_primality_steps() {
    cout << "\nSteps for Monte Carlo Primality Testing (Miller-Rabin):" << endl;
    cout << "  1. If n <= 1, return composite. If n == 2 or 3, return prime." << endl;
    cout << "  2. If n is even, return composite." << endl;
    cout << "  3. Write n-1 as 2^r * d (factor out all powers of 2)." << endl;
    cout << "  4. Repeat exactly k times (fixed rounds, e.g. k = 20):" << endl;
    cout << "       a. Pick a random witness a in [2, n-2]." << endl;
    cout << "       b. Compute x = a^d mod n." << endl;
    cout << "       c. If x == 1 or x == n-1, this round passes — continue." << endl;
    cout << "       d. Repeat up to r-1 times: x = x^2 mod n." << endl;
    cout << "            - If x == n-1, this round passes — break inner loop." << endl;
    cout << "       e. If no squaring produced n-1, n is composite — return false." << endl;
    cout << "  5. After all k rounds pass, return probably prime." << endl;
    cout << "     Error probability ? 4^(-k)." << endl;
    cout << "\nComparisons performed in each round:" << endl;
    cout << "  - x == 1?   (initial modular exponentiation result)" << endl;
    cout << "  - x == n-1? (before and after each squaring step)" << endl;
}

// Displays a comparison of Quick Sort and Rabin-Karp algorithm characteristics.
// Parameters: none
// Returns: void (prints to console)
void print_sort_vs_rk_comparison() {
    cout << "\n[Quick Sort vs Rabin-Karp]" << endl;
    cout << "  Quick Sort:  sorts data    | Las Vegas   | O(n log n) avg, always correct" << endl;
    cout << "  Rabin-Karp:  finds pattern | Monte Carlo | O(n+m) avg, may have false positives" << endl;
}

// Displays a comparison of Las Vegas and Monte Carlo primality testing characteristics.
// Parameters: none
// Returns: void (prints to console)
void print_lv_vs_mc_primality_comparison() {
    cout << "\n[Las Vegas vs Monte Carlo Primality]" << endl;
    cout << "  Las Vegas:   always correct          | runtime varies (randomised trial division)" << endl;
    cout << "  Monte Carlo: fixed runtime           | error probability ? 4^(-k)" << endl;
    cout << "  Las Vegas uses trial division; Monte Carlo uses Miller-Rabin." << endl;
}

// Displays menu for Quick Sort operations.
// Parameters: none
// Returns: void (displays menu and handles user interactions)
void rabin_karp_menu_quick_sort()
{
    while (true) {
        cout << "\n(1) See algorithm steps  (2) Sort a string (3) Return to main menu: ";
        string option;
        getline(cin, option);
        while (option != "1" && option != "2" && option != "3") {
            cout << "Invalid choice. Enter 1, 2, or 3: ";
            getline(cin, option);
        }
        if (option == "1") {
            print_quicksort_steps();
        }
		if (option == "3") {
            break;
        }
        else {
            string input = get_valid_string_input();
            do_quick_sort(input);
            print_quicksort_complexity();
            print_quicksort_summary();
        }
        cout << "\nWould you like to continue with Quick Sort? (y/n): ";
        string again;
        getline(cin, again);
        if (again.empty() || tolower(again[0]) != 'y') {
            break;
        }
    }
}

// Displays primality testing menu and allows user to test numbers.
// Parameters: method - 1 for Las Vegas (randomised trial division), 2 for Monte Carlo (Miller-Rabin)
// Returns: void (displays menu and handles user interactions)
void primality_testing_menu(int method)
{
    while (true) {
        if (method == 1) {
            cout << "\n--- Las Vegas Primality Testing (Randomised Trial Division) ---" << endl;
        }
        else {
            cout << "\n--- Monte Carlo Primality Testing (Miller-Rabin) ---" << endl;
        }
        cout << "(1) See algorithm steps  (2) Test a number  (3) Return to main menu: ";
        string option;
        getline(cin, option);
        while (option != "1" && option != "2" && option != "3") {
            cout << "Invalid choice. Enter 1, 2, or 3: ";
            getline(cin, option);
        }

        if (option == "1") {
            if (method == 1) {
                cout << "\nSteps for Las Vegas Primality Testing (Randomised Trial Division):" << endl;
                cout << "  1. If n <= 1, return false (composite). If n == 2 or 3, return true (prime)." << endl;
                cout << "  2. If n is even, return false (composite)." << endl;
                cout << "  3. Generate a list of all odd numbers from 3 up to ?n (potential divisors)." << endl;
                cout << "  4. Randomly shuffle the list (random order of checking)." << endl;
                cout << "  5. For each divisor d in the shuffled list:" << endl;
                cout << "       - If n % d == 0, return false (composite) immediately." << endl;
                cout << "  6. If no divisor divides n, return true (prime)." << endl;
                cout << "\nKey property: Always correct. Runtime varies because the order of divisors is random." << endl;
                cout << "  - Composite numbers may finish early if a small divisor is found early." << endl;
                cout << "  - Prime numbers must check all divisors up to ?n." << endl;
            }
            else {
                print_monte_carlo_primality_steps();
            }
            continue;
        }
        else if (option == "3") {
            break;
        }

        cout << "\nEnter a number to test for primality: ";
        string num_input;
        getline(cin, num_input);

        if (num_input.empty() || !all_of(num_input.begin(), num_input.end(), ::isdigit)) {
            cout << "Invalid input. Please enter a positive integer." << endl;
            continue;
        }

        long long n;
        try {
            n = stoll(num_input);
            if (n == 0) {
                cout << "Returning to previous menu." << endl;
                break;
            }
        }
        catch (...) {
            cout << "Number too large. Please enter a smaller number." << endl;
            continue;
        }

        bool is_prime = false;
        auto start = high_resolution_clock::now();

        if (method == 1) {
            is_prime = las_vegas_primality(n);
        }
        else {
            is_prime = monte_carlo_primality(n, 20);
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        if (is_prime) {
            cout << n << " is PRIME" << endl;
        }
        else {
            cout << n << " is COMPOSITE" << endl;
        }
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;

        if (method == 1) {
            print_lv_primality_complexity();
            print_lv_primality_summary();
        }
        else {
            print_mc_primality_complexity();
            print_mc_primality_summary();
        }
    }
}

// Displays menu for Rabin-Karp (Monte Carlo) string matching operations.
// Parameters: none
// Returns: void (displays menu and handles user interactions)
void rabin_karp_menu()
{
    while (true) {
        cout << "\n(1) See algorithm steps  (2) Search for a pattern (3) Return to main menu: ";
        string option;
        getline(cin, option);
        while (option != "1" && option != "2" && option != "3") {
            cout << "Invalid choice. Enter 1, 2, or 3: ";
            getline(cin, option);
        }
        if (option == "1") {
            print_rabin_karp_steps();
        }
		if (option == "3") {
            break;
        }
        else {
            string text = get_valid_text_input();
            string pattern = get_valid_pattern_input();
            cout << "\n" << search_pattern(text, pattern) << endl;
            print_rabin_karp_complexity();
            print_rabin_karp_summary();
        }
        cout << "\nWould you like to continue with Rabin-Karp? (y/n): ";
        string again;
        getline(cin, again);
        if (again.empty() || tolower(again[0]) != 'y') {
            break;
        }
    }
}

// Displays the main menu and coordinates all functionality.
// Parameters: none
// Returns: void (displays menu and handles user selection until exit)
void main_menu()
{
    srand(static_cast<unsigned int>(time(0)));
    while (true) {
        cout << "\n========== Randomized Algorithm Calculator ==========" << endl;

        cout << "\nLas Vegas Algorithms:" << endl;
        cout << "1. Random Quick Sort" << endl;
        cout << "2. Primality Testing" << endl;

        cout << "\nMonte Carlo Algorithms:" << endl;
        cout << "3. Rabin-Karp String Matching" << endl;
        cout << "4. Primality Testing" << endl;

        cout << "\nComparisons:" << endl;
        cout << "5. Compare Quick Sort vs Rabin-Karp" << endl;
        cout << "6. Compare Las Vegas vs Monte Carlo Primality Testing" << endl;

        cout << "\n7. Exit" << endl;
        cout << "===============================\n" << endl;
        cout << "Choose an option (1-7): ";
        string choice;
        getline(cin, choice);

        while (choice != "1" && choice != "2" && choice != "3" && choice != "4" &&
            choice != "5" && choice != "6" && choice != "7") {
            cout << "Invalid choice. Enter 1-7: ";
            getline(cin, choice);
        }

        if (choice == "1")      rabin_karp_menu_quick_sort();
        else if (choice == "2") primality_testing_menu(1);
        else if (choice == "3") rabin_karp_menu();
        else if (choice == "4") primality_testing_menu(2);
        else if (choice == "5") comparison_menu();
        else if (choice == "6") primality_comparison_menu();
        else if (choice == "7") {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
    }
}