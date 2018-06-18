#pragma once
#include <bitset>
#include <string>

template<unsigned n>
class Bit {
	template<unsigned m>
	friend size_t text(const Bit<m>&, const Bit<m>&);
public:
	Bit() = default;
	Bit(std::string &s) : bit(s) {}
	void update(size_t pos, bool v) {
		bit.set(pos, v);
	}
private:
	std::bitset<n> bit;
};

template<unsigned m>
size_t text(const Bit<m> &lh, const Bit<m> &rh) {
	auto temp = lh.bit ^  rh.bit;
	temp.flip();
	return temp.count();
}