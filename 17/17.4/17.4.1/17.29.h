#pragma once
#include <random>

using std::uniform_int_distribution;
using std::default_random_engine;

unsigned ran(unsigned s) {
	uniform_int_distribution<unsigned> u;
	default_random_engine e(s);
	return u(e);
}