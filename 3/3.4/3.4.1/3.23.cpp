#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout; using std::cin; using std::endl;

int main()
{
	vector<int> v;
	
	cout << "请输入十个整数：";
	
	for (int i = 0, n; i < 10; ++i)
    {
    	cin >> n;
    	v.push_back(n);
	}
	
	cout << "您输入的十个整数为：";
	
	for (auto i = v.cbegin(); i != v.cend(); ++i)
	    cout << *i << " ";
	cout << endl; 
	
	cout << "改变后的十个整数为：";
	
	for (auto i = v.cbegin(); i != v.cend(); ++i)
	    cout << 2 * *i << " ";
	cout << endl;
	 
	return 0;
}
