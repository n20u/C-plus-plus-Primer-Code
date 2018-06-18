#include <iostream>
#include <vector>

using std::vector;
using std::cout; using std::cin; using std::endl;

int main()
{
	cout << "请输入一组整数：";
	
	int i;
	vector<int> v;
	
	while (cin >> i)
	    v.push_back(i);
		
	return 0;
}
