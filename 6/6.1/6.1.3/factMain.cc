#include <iostream>
#include "E:\C、C++\C++ Primer\6\6.1\6.1.2\Chapter6.h"
#include "E:\C、C++\C++ Primer\6\6.1\6.1.3\fact.cc"

using std::cin; using std::cout; using std::endl;

int main()
{
	cout << "请输入一个整数：";
	
	int i;
	
	cin >> i;
	cout << i << "! is " << fact(i) << endl;
	
	return 0;
}
