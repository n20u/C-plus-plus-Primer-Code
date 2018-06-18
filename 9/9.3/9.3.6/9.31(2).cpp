#include <iostream>
#include <forward_list>

using std::cout; using std::endl;
using std::forward_list;

int main()
{
	forward_list<int> fli{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto piter = fli.before_begin();
	auto iter = fli.begin();
	while (iter != fli.end())
	{
		if (*iter % 2)
		{
			fli.insert_after(piter, *iter);
			piter = iter;
			++iter;
		}
		else
		{
			iter = fli.erase_after(piter);
		}
	}
	for (const auto &i : fli)
	{
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}
