#include <iostream>

using std::cin; using std::cout; using std::endl;

void swap(int *i, int *j)
{
	int *a = i;
	i = j;
	j = a;
}

int main()
{
	int a, b;
	int *i = &a, *j = &b;
	
	cout << "请输入两个整数：" << endl << "*i = ";
	cin >> a;
	cout << "*j = ";
	cin >> b;
    
    swap(i, j);
    
	cout << "交换后的两个整数指针为：" << endl << "*i = " << *i << " *j = " << *j;
	
	return 0;
}
