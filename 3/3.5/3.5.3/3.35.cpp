#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;

int main()
{
	int arr[10];
	
	cout << "请输入十个整数：";
	
	for (int i, j; i < 10; ++i)
	{
		cin >> j;
		arr[i] = j;
	}
	    
	for (auto i : arr)
	    cout << i << " ";
	cout << endl;
	
	for (int *i = begin(arr); i != end(arr); ++i)
	    *i = 0;
	    
	for (auto i : arr)
	    cout << i << " ";
	cout << endl;
	
	return 0;
}
