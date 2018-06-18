#include <string>

using std::string;

string func(const string &name, const string &pre, const string &su)
{
	auto ret = name;
	ret.insert(ret.begin(), pre.begin(), pre.end());
	ret.append(su);
	
	return ret;
}
