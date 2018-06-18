#include <list>
#include <set>
#include "..\..\..\2\2.6\2.6.3\Sales_data.h"

using std::multiset;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	using compareType = bool (*)(const Sales_data&, const Sales_data&);
	multiset<Sales_data, compareType> bookstore(compareIsbn);
	return 0;
}
