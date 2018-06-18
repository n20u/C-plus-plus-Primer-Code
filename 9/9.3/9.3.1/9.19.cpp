#include <iostream>
#include <list>
#include <string>

using std::cin; using std::cout;
using std::list;
using std::string;

int main()
{
	list<string> sli;
	string str;
	while (cin >> str)
	{
		sli.push_back(str);
	}
	for (auto iter = sli.cbegin(); iter != sli.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	return 0;
}
