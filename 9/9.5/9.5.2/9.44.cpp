#include <string>

using std::string;

string Replace(string s, string oldVal, string newVal)
{
	for (string::size_type iter = 0; iter <= s.size() - oldVal.size(); ++iter)
	{
		if (s.substr(iter, oldVal.size()) == oldVal)
		{
			s.replace(iter, oldVal.size(), newVal);
			iter += newVal.size() - 1;
		}
	}
	return s;
}
