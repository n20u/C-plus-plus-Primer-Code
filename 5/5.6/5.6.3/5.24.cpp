#include <iostream>
#include <stdexcept>

using std::cin; using std::cout; using std::endl;
using std::runtime_error;

int main()
{
	cout << "请输入两个整数：";
	
	int i,j;
	
	cin >> i >> j;
	
	if (j == 0)
	{
		throw runtime_error("第二个数是0。");
	}
	cout << i << "除以" << j << "的结果为：" << i / j << endl;
	
	return 0;
}
