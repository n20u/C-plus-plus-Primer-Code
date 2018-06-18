#include <iostream>

using std::cin; using std::cout; using std::endl;

int max(int i, const int *j)
{
	return i > *j ? i : *j;
}

int main()
{
	cout << "请输入两个整数：";
	
	int i,j;
	
	cin >> i >> j;
	cout << "这两个整数中较大的为：" << max(i, &j) << endl;
	
	return 0;
}
