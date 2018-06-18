#include <vector>

using std::vector;

vector<int>::const_iterator find(vector<int>::const_iterator cbegin, vector<int>::const_iterator cend, int i)
{
	for (auto iter = cbegin; cbegin != cend; ++iter)
	{
		if (*iter == i)
		{
			return iter;
		}
	}
	
	return cend;
}
