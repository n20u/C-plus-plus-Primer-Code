#include <iostream>

using std::cin; using std::cout; using std::endl;

int factmain(int val)
{
	int ret = 1;
	
	while (val > 1)
	{
		ret *= val--;
	}
	
	return ret;
}

int main()
{
	cout << "请输入一个整数：";
	
	int i;
	
	cin >> i;
	cout << i << "! is " << factmain(i) << endl;
	
	return 0;
}
