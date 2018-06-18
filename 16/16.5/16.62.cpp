#include "Sales_data.h"
#include <unordered_set>
#include <algorithm>
#include <iostream>

using std::unordered_multiset;
using std::for_each;
using std::cout;
using std::endl;

namespace std {
	template<>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s) const;
	};
	size_t hash<Sales_data>::operator()(const Sales_data& s) const {
		return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
	}
}

int main() {
	unordered_multiset<Sales_data> mset;
	mset.emplace("C++", 10, 15);
	mset.emplace("C", 5, 10);
	mset.emplace("Java", 10, 10);
	for_each(mset.cbegin(), mset.cend(), [](const Sales_data &s) { cout << s << endl; });
	system("pause");
	return 0;
}