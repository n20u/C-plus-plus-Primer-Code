#include <iostream>
#include <initializer_list>

using std::cin; using std::cout; using std::endl;
using std::initializer_list;

int sum_list(initializer_list<int> li)
{
	int sum = 0;
	
	for (auto beg = li.begin(); beg != li.end(); ++beg)
	{
		sum += *beg;
	}
	
	return sum;
}

int main()
{
	cout << "请输入三个整数：";
	
	int a, b, c;
	
	cin >> a >> b >> c;
	
	cout << a << "+" << b << "+" << c << "=" << sum_list({a, b, c}) << endl;
	
	return 0;
}
