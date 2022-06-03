#pragma once

#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cctype>
#include <algorithm>

using std::pair;
using std::vector;
using std::string;
using std::unique_ptr;
using std::make_unique;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::cout;
using std::endl;
using std::cerr;

const char EMPTY = ' ';
const char WHITE_KING = 'K';
const char BLACK_KING = 'k';

const int BOARD_SIZE = 8;

enum Max {
	Width = 40,
	Height = 20,
	RandomMonkey = 5
};
