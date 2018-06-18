#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

void fun(vector<int> ivec, int j)
{	
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
	cout << "请输入用于初始化vector对象的整数：";
	
	vector<int> ivec;
	
	for (int i = 0; i < 10; ++i)
	{
		int j;
		cin >> j;
		ivec.push_back(j);
	}
	
	cout << "vector对象初始化完成！请再输入一个1~10之间的整数：";
	int j;
	cin >> j;
	cout << "vector对象中第" << j <<"个元素到最后一个元素为：";
	
	fun(ivec, j);
	
	return 0;
}
