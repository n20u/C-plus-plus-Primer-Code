#include <iostream>

using std::cin; using std::cout;

int main()
{
	cout << "输入两个整数：";
	
	int i = 0, j = 0;
	
	cin >> i >> j;
	
	while (i >= j)
	{
		cout << i-- << " ";
	}
	
	return 0;
} 
