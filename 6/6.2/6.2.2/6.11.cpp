#include <iostream>
#include <iomanip>

using std::cin; using std::cout; using std::endl;
using std::setw; using std::setfill;

void reset(int &i)
{
	i = 0;
}

int main()
{
	int j;
	
	cout << "请输入整数j = ";
	cin >> j;
	
	reset(j);
	
	cout << setfill('-') << setw(20) << "" << endl;
	cout << "经过reset处理的整数j = " << j << endl;
	
	return 0;
}
