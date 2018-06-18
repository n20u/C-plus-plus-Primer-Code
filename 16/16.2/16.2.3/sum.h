#pragma once
template<typename T>
auto sum(const T &a, const T &b) -> decltype(a + b) {
	return a + b;
}