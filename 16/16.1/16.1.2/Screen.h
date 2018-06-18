#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using pos = std::string::size_type;

template<pos M, pos N>
class Screen
{
public:
	Screen() = default;
	char get() const
	{
		return contents[cursor];
	}
	char get(pos ht, pos wd) const
	{
		if (ht < height && wd < width && ht * width + wd < cursor) {
			return contents[ht * width + wd];
		}
		return ' ';
	}
	Screen &move(pos ht, pos wd)
	{
		cursor = ht * width + wd;
		return *this;
	}
	Screen &set(char c)
	{
		contents.push_back(c);
		++cursor;
		cursor = std::min(cursor, height * width);
		return *this;
	}
	Screen &set(pos ht, pos wd, char c)
	{
		if (ht < height && wd < width) {
			if (ht * width + wd < cursor) {
				contents[ht * width + wd] = c;
			}
			else {
				contents.insert(contents.end(), ht * width + wd - cursor, ' ');
				contents.push_back(c);
				cursor = ht * width + wd + 1;
			}
		}
		return *this;
	}
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}
	pos cap() const {
		return cursor;
	}
private:
	void do_display(std::ostream &os) const
	{
		os << contents;
	}
	pos cursor = 0;
	pos height = M, width = N;
	std::string contents;
};

template<pos M, pos N>
std::istream& operator>>(std::istream &is, Screen<M, N> &s) {
	std::string input;
	is >> input;
	for (char c : input) {
		s.set(c);
	}
	return is;
}
template<pos M, pos N>
std::ostream & operator<<(std::ostream &os, const Screen<M, N> &s)
{
	for (pos i = 0; i < M; ++i) {
		for (pos j = 0; j < N; ++j) {
			if (i * N + j < s.cap()) {
				os << s.get(i, j);
			}
		}
		if ((i + 1) * N < s.cap()) {
			os << std::endl;
		}
	}
	return os;
}