#pragma once
#include <random>

using std::uniform_int_distribution;
using std::default_random_engine;

int ran(unsigned s, int min, int max) {
	uniform_int_distribution<int> u(min, max);
	default_random_engine e(s);
	return u(e);
}