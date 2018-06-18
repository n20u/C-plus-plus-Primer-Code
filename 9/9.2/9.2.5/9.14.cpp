#include <list>
#include <vector>
#include <string>

using std::list;
using std::vector;
using std::string;

int main()
{
	list<char *> clist(10, "Hiya!");
	vector<string> svec(clist.cbegin(), clist.cend());
	
	return 0;
}
