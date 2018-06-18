#include <iostream>

using std::cin; using std::cout; using std::endl;

void fact(int val)
{
	cout << abs(val) << endl;
}

int main()
{
	cout << "请输入一个整数：";
	
	int i;
	
	cin >> i;
	cout << "该整数的绝对值为：";
	
	fact(i);
	
	return 0;
}
