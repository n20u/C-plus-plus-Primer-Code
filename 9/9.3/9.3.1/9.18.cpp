#include <iostream>
#include <deque>
#include <string>

using std::cin; using std::cout;
using std::deque;
using std::string;

int main()
{
	deque<string> sdeq;
	string str;
	while (cin >> str)
	{
		sdeq.push_back(str);
	}
	for (auto iter = sdeq.cbegin(); iter != sdeq.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	return 0;
}
