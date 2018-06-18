#include <iostream>
#include <vector>
#include <cstddef>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::begin; using std::end;

int main()
{
	vector<int> ivec;
	
	cout << "请输入十个用于初始化含有整数元素的vector对象的整数：";
	
	for (int i = 0, j; i < 10; ++i)
	{
		cin >> j;
		ivec.push_back(j);
	}
	
	cout << "含有整数元素的vector对象为：";
	
	for (auto i : ivec)
	    cout << i << " ";
	cout << endl;

	int int_arr[10];
	size_t j = 0;
	
	for (auto i = ivec.begin(); i != ivec.end() && j < 10; ++i, ++j)
        int_arr[j] = *i;
    
    cout << "拷贝含有整数元素的vector对象的整型数组为：";
	
	for (auto i : int_arr)
	    cout << i << " "; 
	cout << endl;
		
	return 0;
}
