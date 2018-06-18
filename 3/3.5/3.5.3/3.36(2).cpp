#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::end;

int main()
{
	vector<int> v, v1;
	
	cout << "请输入十个整数：";
	
	for (int i = 0, j; i < 10; ++i)
	{
		cin >> j;
		v.push_back(i);
	}
	    
	cout << "请再输入十个整数：";
	
	for (int i = 0, j; i < 10; ++i)
	{
		cin >> j;
		v1.push_back(i);
	}
	
	cout << "前十个整数为：";
	
	for (auto i : v)
	    cout << i << " ";
	cout << endl;
	
	cout << "后十个整数为：";
	
	for (auto i : v1)
	    cout << i << " ";
	cout << endl;
	    
	if (v == v1)
	    cout << "两个vector对象相等";
	else
	    cout << "两个vector对象不相等";
		 
	return 0;
}
