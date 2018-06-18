#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;

int main()
{
	int arr[10], arr1[10];
	
	cout << "请输入十个整数：";
	
	for (int i, j; i < 10; ++i)
	{
		cin >> j;
		arr[i] = j;
	}
	
	cout << "请再输入十个整数：";
	
	for (int i, j; i < 10; ++i)
	{
		cin >> j;
		arr1[i] = j;
	}
	
	cout << "前十个整数为：";
	
	for (auto i : arr)
	    cout << i << " ";
	cout << endl;
	
	cout << "后十个整数为：";
	
	for (auto i : arr1)
	    cout << i << " ";
	cout << endl;
	
	bool a = true;
		
	for (int *i = begin(arr), *j = begin(arr1); i != end(arr) && j != end(arr1); ++i, ++j)
	{
		if (*i != *j)
		{
			a = false;
			cout << "两个数组不相等。";
		    break;
		}
	}
	
    if (a)
        cout << "两个数组相等";
	
	return 0;
}
