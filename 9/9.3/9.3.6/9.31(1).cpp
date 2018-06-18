#include <iostream>
#include <list>

using std::cout; using std::endl;
using std::list;

int main()
{
	list<int> li{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = li.begin();
	while (iter != li.end())
	{
		if (*iter % 2)
		{
			li.insert(iter, *iter);
			++iter;
		}
		else
		{
			iter = li.erase(iter);
		}
	}
	for (const auto &i : li)
	{
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}
