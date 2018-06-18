#include <iostream>
#include <iomanip>

using std::cin; using std::cout; using std::endl;
using std::setw; using std::setfill;

void swap(int *i, int *j)
{
	int a = *i;
	*i = *j;
	*j = a;
}

int main()
{
	int i,j;
	
	cout << "请输入两个整数：" << endl << "i = ";
	cin >> i;
	cout << "j = ";
	cin >> j;
	
	swap(&i, &j);
	
	cout << setfill('-') << setw(20) << "" << endl;
	cout << "交换两个整数后的结果：" << "i = " << i << ",j = " << j << endl;
	
	return 0;
}
