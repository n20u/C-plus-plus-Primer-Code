#pragma once
#include <vector>
#include <algorithm>
#include <cstring>

template<typename T>
int count(T t, std::vector<T> tvec) {
	return std::count(tvec.cbegin(), tvec.cend(), t);
}

template<>
int count(const char *t, std::vector<const char*> cvec) {
	return std::count_if(cvec.cbegin(), cvec.cend(), [t](const char *c) { return std::strcmp(t, c) == 0; });
}