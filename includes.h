//Author: Lianet Caldero
//Course: Data Structures and Algorithms
//Professor: Ali
//Assignment: Programming Project
//includes.h

#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <cmath>
#include "menu.h"
using namespace std::chrono;
using namespace std;

inline bool has_letter(const std::string& s) {
    for (char c : s) {
        if (isalpha(static_cast<unsigned char>(c))) return true;
    }
    return false;
}

