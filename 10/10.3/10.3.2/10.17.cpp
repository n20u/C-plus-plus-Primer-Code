#include <algorithm>
#include <vector>
#include <iostream>
#include "..\..\..\2\2.6\2.6.3\Sales_data.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<Sales_data> svec{{"The Brower Hacker's Handbook", 54.99, 4}, {"The Web Application Hacker's Handbook", 50, 23}, {"Hackers and Painters", 12, 1079}, {"An Introduction to General Systems Thinking", 30, 30}};
	cout << "排序前为：" << endl;
	for (const auto &s : svec)
	{
		cout << s.bookNo << " " << s.units_sold << " " << s.revenue << " " << endl;
	}
	cout << "排序后为：" << endl;
	sort(svec.begin(), svec.end(), [](Sales_data &s1, Sales_data &s2){ return s1.isbn() < s2.isbn(); });
	for (const auto &s : svec)
	{
		cout << s.bookNo << " " << s.units_sold << " " << s.revenue << " " << endl;
	}
	system("pause");
	return 0;
}
