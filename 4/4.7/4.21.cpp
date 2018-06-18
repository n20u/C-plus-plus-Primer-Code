#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
	vector<int> ivec;
	int i;
	
	cout << "请输入用于初始化vector<int>的整数：";
	
	while (cin >> i)
	    ivec.push_back(i);
	    
	cout << "vector<int>为：";
	
	for (auto i : ivec)
	    cout << i << " ";
	cout << endl;
	
	cout << "奇数值翻倍后的vector<int>为：";
	
	for (auto i : ivec)
	    cout << (i % 2 == 0 ? i : 2 * i) << " ";
	cout << endl;
	
	return 0;
}
