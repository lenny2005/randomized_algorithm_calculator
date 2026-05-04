//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//monte_carlo.cpp
// AI Usage: ai was used in the generation of comments about function definitions and their parameters.

//This file contains the implementation of the Monte Carlo primality testing algorithm.
//- Monte Carlo Primality Testing (Miller-Rabin)
//Unlike Las Vegas, this algorithm runs a fixed number of rounds and has a small
//probability of error, but guarantees a bounded runtime.

#include "includes.h"
#include "las_vegas.h"

extern mt19937 gen;

// Monte Carlo primality test - fixed runtime with bounded error probability.
// Runs exactly k rounds of Miller-Rabin witness testing.
// Each round uses a randomly selected witness to check if n is composite.
// Parameters: n - the number to test for primality, k - the number of rounds (default 20)
// Returns: true if n is probably prime (error probability <= 4^(-k)), false if definitely composite
bool monte_carlo_primality(long long n, int k) {
    cout << "Testing: " << n << endl;
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

	//AI Usage: ai suggested using this (line 30) as opposed to long long a = 2 + (rand() % (n - 3)) because it wpuld be more efficient and less error-prone. It also ensures uniform distribution of random witnesses.
    uniform_int_distribution<long long> dis(2, n - 2);

    for (int i = 0; i < k; i++) {
        long long a = dis(gen);
        if (!miller_rabin_witness(n, a)) {
            return false; 
        }
    }
    return true; 
}