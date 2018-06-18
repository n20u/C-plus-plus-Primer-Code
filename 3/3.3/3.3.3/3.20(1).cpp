#include <iostream>
#include <vector>

using std::vector;
using std::cin; using std::cout; using std::endl;

int main()
{
	int i;
	vector<int> v;
	
	cout << "请输入一组整数：";
	
	while(cin >> i)
	    v.push_back(i);

	for (vector<int>::size_type j = 0; j < v.size(); j += 2)
	{		
		cout << (j + 1 < v.size() ? v[j] + v[j + 1] : v[j]) << " ";
	}
	
	return 0;
}
