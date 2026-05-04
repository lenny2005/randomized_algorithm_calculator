# Randomized Algorithms: Las Vegas & Monte Carlo
**Course:** Data Structures and Algorithms
**Author:** Lianet Caldero
**Professor:** Ali

---

## Project Description

This project demonstrates and compares two categories of randomized algorithms:

- **Las Vegas Algorithms** — always produce a correct result, but runtime varies
- **Monte Carlo Algorithms** — run in fixed time, but have a small probability of error

The program implements four algorithms across these two categories:

| Algorithm | Category | Purpose |
|---|---|---|
| Random Quick Sort | Las Vegas | Sorts a string using a randomized pivot |
| Miller-Rabin Primality (Las Vegas) | Las Vegas | Tests if a number is prime, always correct |
| Rabin-Karp String Matching | Monte Carlo | Searches for a pattern inside a string using rolling hash |
| Miller-Rabin Primality (Monte Carlo) | Monte Carlo | Tests if a number is prime with bounded error probability |

---

## File Structure

```
project/
├── compare_search_dsa.cpp       — Entry point, calls main_menu()
├── menu.cpp / menu.h            — All menus and user interaction
├── las_vegas.cpp / las_vegas.h  — Quick Sort and Las Vegas primality testing
├── monte_carlo.cpp / monte_carlo.h      — Monte Carlo primality testing
├── rabin_karp.cpp / rabin_karp.h        — Rabin-Karp string matching
├── comparison.cpp / comparison.h        — Quick Sort vs Rabin-Karp comparison
├── primality_comparison.cpp / .h        — Las Vegas vs Monte Carlo comparison
└── includes.h                           — Shared standard library headers
```

---

## Setup & Running in Visual Studio

1. Open `compare_search_dsa.slnx` in Visual Studio
2. Make sure all `.cpp` and `.h` files are visible in the Solution Explorer — if any are missing, right-click the project and select **Add > Existing Item**
3. Set the build configuration to **Debug** or **Release** (either works)
4. Press **Ctrl+F5** to build and run without the debugger, or **F5** to run with it
5. The program will launch in a console window with the main menu

---

## How to Use

When launched, the program presents a main menu:

```
========== Main Menu ==========

Las Vegas Algorithms:
1. Random Quick Sort
2. Primality Testing

Monte Carlo Algorithms:
3. Rabin-Karp String Matching
4. Primality Testing

Comparisons:
5. Compare Quick Sort vs Rabin-Karp
6. Compare Las Vegas vs Monte Carlo Primality Testing

7. Exit
```

**Option 1 — Random Quick Sort**
Choose to view the algorithm steps or sort a string. If multiple words are detected, choose to sort all letters together or each word separately.

**Option 2 — Las Vegas Primality Testing**
Enter any positive integer to test. The result (PRIME or COMPOSITE) is always correct. After testing, you can view the step-by-step witness rounds.

**Option 3 — Rabin-Karp String Matching**
Choose to view the algorithm steps or search for a pattern. Enter a text string and a pattern — all match positions and total match count are displayed.

**Option 4 — Monte Carlo Primality Testing**
Enter any positive integer to test. The result is probably correct with error probability at most 4^(-20).

**Option 5 — Compare Quick Sort vs Rabin-Karp**
Enter a number of iterations and test data. Both algorithms run on the same input and a side-by-side timing summary is displayed.

**Option 6 — Compare Las Vegas vs Monte Carlo Primality**
Enter how many numbers to test and a range (e.g. `100-10000`). Both algorithms run on the same randomly generated numbers and a summary shows timing and prime count results.

---

## AI Usage Disclosure

AI was used to assist in generating function definition comments and parameter descriptions throughout the source files. All algorithm logic, structure, and design decisions were written by the author.