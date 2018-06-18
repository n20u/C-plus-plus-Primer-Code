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

	for (auto j = v.cbegin(); j != v.cend(); j += 2)
	{		
		if (j + 1 != v.cend())
		    cout << *j + *(j + 1) << " ";
		else
		{
			cout << *j << endl;
			break;
		}
	}
	
	return 0;
}
