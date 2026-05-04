//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//las_vegas.h
#pragma once
#include "includes.h"

// Las Vegas Algorithms: Random Quick Sort and Primality Testing
// Both have variable runtime but are always correct

// Quick Sort Functions
string random_quick_sort(string);
string get_valid_string_input();
void do_quick_sort(const string&);
string normalize_string(const string&, bool);
string sort_as_one_string(const string&);
string sort_each_word(const string&);

// Las Vegas Primality Testing Functions
long long mod_pow(long long base, long long exp, long long mod);
bool miller_rabin_witness(long long n, long long a);
bool las_vegas_primality(long long n);
void show_primality_steps(long long n);