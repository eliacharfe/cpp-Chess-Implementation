#pragma once
#include "Utilities.h"

typedef struct Location
{
	char l;
	int n;

	Location() : l('a'), n(0){}

	Location(char letter, int n) : l(letter), n(n)
	{ }

	~Location() { }

	Location operator()(char l, int n) {
		Location location;
	    location.l = l;
		location.n = n;
		return location;
	}

} Location;

std::ostream& operator<<(std::ostream& os, const Location& location);
const bool operator==(const Location& loc1, const Location& loc2);
const bool operator!=(const Location& loc1, const Location& loc2);
