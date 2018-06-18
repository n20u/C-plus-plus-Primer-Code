#include <iostream>
#include <iterator>
#include <vector>
#include "..\..\..\2\2.6\2.6.3\Sales_data.h"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

bool compareIsbn (Sales_data &s1, Sales_data &s2)
{
	return s1.isbn() < s2.isbn();
}

int main()
{
	cout << "输入交易记录：";
	istream_iterator<Sales_data> item_iter(cin), eof;
	vector<Sales_data> total(item_iter, eof);
	sort(total.begin(), total.end(), compareIsbn);
	for(auto iter = total.cbegin(), result = iter; iter != total.cend(); iter = result)
	{
		result = find_if(iter, total.cend(), [iter](const Sales_data &data){ return data.isbn() != iter->isbn(); });
		cout << accumulate(iter, result, Sales_data(iter->isbn())) << endl;
	}
	return 0;
}
