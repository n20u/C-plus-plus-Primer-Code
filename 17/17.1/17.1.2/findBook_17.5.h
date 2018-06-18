#pragma once
#include <vector>
#include <pair>
#include <string>
#include <algorithm>
#include "../../../16/16.5/Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}

struct matches
{
	friend class Sales_data;

	matches(std::vector<Sales_data>::size_type index,
		std::vector<Sales_data>::const_iterator begin,
		std::vector<Sales_data>::const_iterator end) : index(index), begin(begin), end(end) {}

	std::vector<Sales_data>::size_type index;
	std::vector<Sales_data>::const_iterator begin;
	std::vector<Sales_data>::const_iterator end;
};

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string &book) {
	std::vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second) {
			ret.push_back(matches(it - files.cbegin(), found.first, found.second));
		}
	}
	return ret;
}