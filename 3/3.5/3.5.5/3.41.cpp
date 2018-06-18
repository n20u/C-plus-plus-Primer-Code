#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::begin; using std::end;

int main()
{
	int int_arr[10];
	
	cout << "请输入十个用于初始化整型数组的整数：";
	
	for (int i = 0, j; i < 10; ++i)
	{
		cin >> j;
		int_arr[i] = j;
	}
	
	cout << "整型数组为：";
	
	for (auto i : int_arr)
	    cout << i << " ";
	cout << endl;
	
	vector<int> ivec(begin (int_arr), end(int_arr));
	
	cout << "用整型数组初始化的vector对象为：";
	
	for (auto i : ivec)
	    cout << i << " ";
	
	return 0;
}
