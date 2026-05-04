//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//monte_carlo.cpp
#include "includes.h"
#include "las_vegas.h"

extern mt19937 gen;
// Monte Carlo Primality Testing - Fixed runtime, small error probability
// Runs exactly k rounds with bounded error probability
bool monte_carlo_primality(long long n, int k) {
    cout << "Testing: " << n << endl;
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    mt19937 gen(time(0));
    uniform_int_distribution<long long> dis(2, n - 2);

    for (int i = 0; i < k; i++) {
        long long a = dis(gen);
        if (!miller_rabin_witness(n, a)) {
            return false;  // n is composite (definitive)
        }
    }
    return true;  // Probably prime (error probability <= 4^(-k))
}
