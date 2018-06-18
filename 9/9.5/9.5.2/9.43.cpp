#include <string>

using std::string;

string Replace(string s, string oldVal, string newVal)
{
	for (auto iter = s.begin(); iter <= s.end() - oldVal.size() + 1; ++iter)
	{
		string str;
		str.assign(iter, iter + oldVal.size());
		if (str == oldVal)
		{
			iter = s.erase(iter, iter + oldVal.size());
			iter = s.insert(iter, newVal.begin(), newVal.end());
			iter += newVal.size();
		}
	}
	return s;
}
