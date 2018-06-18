#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "Ô­ÐòÎª£º";
	for_each(vec.cbegin(), vec.cend(), [](const int &i){cout << i << " ";});
	cout << endl;
	cout << "ÄæÐòÎª£º";
	auto iter = vec.cend();
	while(true)
	{
		if(iter == vec.cbegin())
		{
			break;
		}
		else
		{
			cout << *--iter << " ";
		}
	}
	return 0;
}
