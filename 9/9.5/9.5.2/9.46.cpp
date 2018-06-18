#include <string>

using std::string;

string func(const string &name, const string &pre, const string &su)
{
	auto ret = name;
	ret.insert(0, pre);
	ret.insert(ret.size(), su);
	
	return ret;
}
