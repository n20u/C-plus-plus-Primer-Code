#include <forward_list>
#include <string>

using std::forward_list;
using std::string;

forward_list<string> &insert(forward_list<string> &flst, const string &find, const string &insrt)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr == find)
		{
			flst.insert_after(curr, insrt);
			return flst;
		}
		++prev;
		++curr;
	}
	flst.insert_after(prev, insrt);
	return flst;
}
