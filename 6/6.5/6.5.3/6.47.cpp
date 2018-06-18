#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

void fun(vector<int> ivec, int j = 1)
{
	#ifndef NDEBUG
	    cout << "vector对象的大小为：" << ivec.size() << "——";
	#endif
	 
	if (j < 10)
	{
		cout << ivec[j - 1] << " ";
		++j;
		fun(ivec, j);
	}
	else
	{
		cout << ivec[j - 1] << endl;
	}
	
}

int main()
{
	cout << "请输入十个用于初始化vector对象的整数：";
	
	vector<int> ivec;
	
	for (int i = 0; i < 10; ++i)
	{
		int j;
		cin >> j;
		ivec.push_back(j);
	}
	
	cout << "vector对象的内容为：" << endl;
	
	fun(ivec);
	
	return 0;
}
