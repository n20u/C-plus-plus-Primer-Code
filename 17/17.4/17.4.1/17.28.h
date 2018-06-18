#pragma once
#include <random>

using std::uniform_int_distribution;
using std::default_random_engine;

unsigned ran() {
	uniform_int_distribution<unsigned> u;
	default_random_engine e;
	return u(e);
}