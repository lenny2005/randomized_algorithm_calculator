//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//rabin_karp.h
#pragma once
#include "includes.h"

void rabin_karp_menu();
vector<int> rabin_karp_search(const string& text, const string& pattern);
string normalize_string_rk(const string& input, bool keep_spaces = false);
string get_valid_text_input();
string get_valid_pattern_input();
string search_pattern(const string& text, const string& pattern);