//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//menu.cpp
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
// Explains the partitioning process, recursion, and randomization strategy.
// Parameters: none
// Returns: void (prints to console)
void print_quicksort_steps() {
    cout << "\nSteps for Random Quick Sort (Las Vegas):" << endl;
    cout << "  1. If the array has 0 or 1 element, it is already sorted return." << endl;
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

// Displays the time and space complexity analysis of Las Vegas Primality Testing algorithm.
// Parameters: none
// Returns: void (prints to console)
void print_lv_primality_complexity() {
    cout << "\n[Las Vegas Primality - Miller-Rabin]" << endl;
    cout << "  Time:  O(k log^2 n) | k = variable rounds" << endl;
    cout << "  Space: O(1)" << endl;
}

// Displays a summary and use-case recommendation for Las Vegas Primality Testing.
// Parameters: none
// Returns: void (prints to console)
void print_lv_primality_summary() {
    cout << "\nSummary: Las Vegas Primality (Miller-Rabin)" << endl;
    cout << "- Always correct, but runtime can vary depending on witnesses." << endl;
    cout << "- Used when you need guaranteed correctness for primality." << endl;
}

// Displays the time and space complexity analysis of Rabin-Karp string matching algorithm.
// Parameters: none
// Returns: void (prints to console)
void print_rabin_karp_complexity() {
    cout << "\n[Rabin-Karp - Monte Carlo]" << endl;
    cout << "  Time:  O(n+m) avg | O(nm) worst (hash collisions)" << endl;
    cout << "  Space: O(1)" << endl;
}

// Displays a summary and use-case recommendation for Rabin-Karp string matching.
// Parameters: none
// Returns: void (prints to console)
void print_rabin_karp_summary() {
    cout << "  -> Use Rabin-Karp for fast pattern search with acceptable error rate." << endl;
}

// Displays detailed step-by-step explanation of Rabin-Karp string matching algorithm.
// Explains rolling hash calculation, window sliding, and verification process.
// Parameters: none
// Returns: void (prints to console)
void print_rabin_karp_steps() {
    cout << "\nSteps for Rabin-Karp String Matching (Monte Carlo):" << endl;
    cout << "  1. Compute a rolling hash of the pattern (length m)." << endl;
    cout << "  2. Compute the hash of the first m characters of the text." << endl;
    cout << "  3. Slide a window of size m across the text, one character at a time:" << endl;
    cout << "       a. If the window hash matches the pattern hash:" << endl;
    cout << "            - Verify character by character to confirm a true match." << endl;
    cout << "            - If confirmed, record the position." << endl;
    cout << "       b. Remove the leftmost character from the hash (subtract its contribution)." << endl;
    cout << "       c. Add the next character to the hash (rolling update)." << endl;
    cout << "  4. Report all positions where a true match was found." << endl;
    cout << "\nComparisons performed:" << endl;
    cout << "  - Hash comparison at each window position: O(1) per step." << endl;
    cout << "  - Character-by-character verification only on hash matches." << endl;
    cout << "  - Hash collisions are false positives — verification prevents false results." << endl;
}

// Displays the time and space complexity analysis of Monte Carlo Primality Testing algorithm.
// Parameters: none
// Returns: void (prints to console)
void print_mc_primality_complexity() {
    cout << "\n[Monte Carlo Primality - Miller-Rabin]" << endl;
    cout << "  Time:  O(k log^2 n) | k = fixed rounds" << endl;
    cout << "  Space: O(1)" << endl;
}

// Displays a summary and use-case recommendation for Monte Carlo Primality Testing.
// Parameters: none
// Returns: void (prints to console)
void print_mc_primality_summary() {
    cout << "  -> Use Monte Carlo when speed matters more than absolute certainty." << endl;
}

// Displays detailed step-by-step explanation of Monte Carlo Primality Testing algorithm.
// Explains the fixed k-rounds of witness testing and error probability bounds.
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
    cout << "            - If x == 1, n is composite — return false immediately." << endl;
    cout << "       e. If no squaring produced n-1, n is composite — return false." << endl;
    cout << "  5. After all k rounds pass, return probably prime." << endl;
    cout << "     Error probability is at most 4^(-k)." << endl;
    cout << "\nComparisons performed in each round:" << endl;
    cout << "  - x == 1?   (initial modular exponentiation result)" << endl;
    cout << "  - x == n-1? (before and after each squaring step)" << endl;
}

// Displays a comparison of Quick Sort and Rabin-Karp algorithm characteristics.
// Parameters: none
// Returns: void (prints to console)
void print_sort_vs_rk_comparison() {
    cout << "\n[Quick Sort vs Rabin-Karp]" << endl;
    cout << "  Quick Sort:  sorts data    | Las Vegas   | O(n log n) avg" << endl;
    cout << "  Rabin-Karp:  finds pattern | Monte Carlo | O(n+m) avg" << endl;
    cout << "  Both always return correct results." << endl;
}

// Displays a comparison of Las Vegas and Monte Carlo primality testing characteristics.
// Parameters: none
// Returns: void (prints to console)
void print_lv_vs_mc_primality_comparison() {
    cout << "\n[Las Vegas vs Monte Carlo Primality]" << endl;
    cout << "  Las Vegas:   always correct  | runtime varies" << endl;
    cout << "  Monte Carlo: fixed runtime   | error prob <= 4^(-k)" << endl;
    cout << "  Both use Miller-Rabin witness testing." << endl;
}

// Displays menu for Quick Sort operations with options to view algorithm steps or sort a string.
// Allows user to repeatedly perform sorting operations until choosing to exit.
// Parameters: none
// Returns: void (displays menu and handles user interactions)
void rabin_karp_menu_quick_sort()
{
    while (true) {
        cout << "\n(1) See algorithm steps  (2) Sort a string: ";
        string option;
        getline(cin, option);
        while (option != "1" && option != "2") {
            cout << "Invalid choice. Enter 1 or 2: ";
            getline(cin, option);
        }
        if (option == "1") {
            print_quicksort_steps();
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

// Displays primality testing menu and allows user to test numbers for primality.
// Supports both Las Vegas and Monte Carlo methods based on the method parameter.
// Provides options to view algorithm details or test a number.
// Parameters: method - 1 for Las Vegas, 2 for Monte Carlo
// Returns: void (displays menu and handles user interactions)
void primality_testing_menu(int method)
{
    while (true) {
        cout << "\nEnter a number to test for primality (or 0 to return): ";
        string num_input;
        getline(cin, num_input);

        if (num_input == "0") break;

        if (!all_of(num_input.begin(), num_input.end(), ::isdigit)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        long long n = stoll(num_input);
        bool is_prime = false;
        auto start = high_resolution_clock::now();

        if (method == 1) {
            cout << "\n--- Las Vegas Primality Testing ---" << endl;
            cout << "(1) See algorithm  (2) Test a number: ";
            string option;
            getline(cin, option);
            while (option != "1" && option != "2") {
                cout << "Invalid choice. Enter 1 or 2: ";
                getline(cin, option);
            }

            if (option == "1") {
                cout << "\nSteps for Las Vegas Primality Testing:" << endl;
                cout << "  1. Write n-1 as 2^r * d (factor out powers of 2)." << endl;
                cout << "  2. Pick a random witness a in [2, n-2]." << endl;
                cout << "  3. Compute x = a^d mod n." << endl;
                cout << "  4. If x == 1 or x == n-1, n passes this round (likely prime for this witness)." << endl;
                cout << "  5. Otherwise, repeat up to r-1 times: x = x^2 mod n; if x == n-1, n passes this round." << endl;
                cout << "  6. If x never becomes n-1, n is composite (definitely not prime)." << endl;
                cout << "  7. Repeat with new random witnesses until a definitive answer is found." << endl;
                cout << "  8. If no witness proves composite after many rounds, n is declared prime." << endl;
                cout << "\nComparisons performed in each round:" << endl;
                cout << "  - x == 1? (Is the initial power congruent to 1 mod n)" << endl;
                cout << "  - x == n-1? (Is the initial or any squared value congruent to n-1 mod n)" << endl;
                cout << "  - If neither, n is composite for this witness." << endl;
                continue;
            }
            else {
                is_prime = las_vegas_primality(n);
            }
        }
        else {
            cout << "\n--- Monte Carlo Primality Testing ---" << endl;
            cout << "(1) See algorithm  (2) Test a number: ";
            string option;
            getline(cin, option);
            while (option != "1" && option != "2") {
                cout << "Invalid choice. Enter 1 or 2: ";
                getline(cin, option);
            }
            if (option == "1") {
                print_monte_carlo_primality_steps();
                continue;
            }
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
            while (true) {
                cout << "\nOptions: (1) See steps  (2) Test another  (3) Go back\nChoose: ";
                string opt;
                getline(cin, opt);
                if (opt == "1") {
                    las_vegas_primality(n);
                }
                else if (opt == "2") {
                    break;
                }
                else if (opt == "3") {
                    return;
                }
                else {
                    cout << "Invalid option. Please enter 1, 2, or 3." << endl;
                }
            }
        }
        else {
            print_mc_primality_complexity();
            print_mc_primality_summary();
        }
    }
}

// Displays menu for Rabin-Karp string matching operations.
// Allows user to view algorithm steps or search for patterns in text.
// Provides repeated operation capability until user chooses to exit.
// Parameters: none
// Returns: void (displays menu and handles user interactions)
void rabin_karp_menu()
{
    while (true) {
        cout << "\n(1) See algorithm steps  (2) Search for a pattern: ";
        string option;
        getline(cin, option);
        while (option != "1" && option != "2") {
            cout << "Invalid choice. Enter 1 or 2: ";
            getline(cin, option);
        }
        if (option == "1") {
            print_rabin_karp_steps();
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

// Displays the main menu for the Randomized Algorithm Calculator application.
// Provides access to Las Vegas algorithms, Monte Carlo algorithms, and comparison tools.
// Handles user selection and routes to appropriate submenus until exit.
// Parameters: none
// Returns: void (displays menu and coordinates navigation)
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