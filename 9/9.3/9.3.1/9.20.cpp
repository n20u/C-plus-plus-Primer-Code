#include <iostream>
#include <list>
#include <deque>

using std::cin; using std::cout; using std::endl;
using std::list;
using std::deque;

int main()
{
	cout << "请输入用于初始化list<int>对象的整数：";
	int i;
	list<int> ili;
	while (cin >> i)
	{
		ili.push_back(i);
	}
	deque<int> ideq1, ideq2;
	for (const auto &i : ili)
	{
		i % 2 == 0 ? ideq1.push_back(i) : ideq2.push_back(i);
	}
	cout << "值为偶数的整数为：";
	for (const auto &i : ideq1)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "值为奇数的整数为：";
	for (const auto &i : ideq2)
	{
		cout << i << " ";
	 } 
	return 0;
}
