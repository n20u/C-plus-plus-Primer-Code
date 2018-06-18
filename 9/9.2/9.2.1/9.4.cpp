#include <vector>

using std::vector;

bool find(vector<int>::const_iterator cbegin, vector<int>::const_iterator cend, int i)
{
	for (auto iter = cbegin; cbegin != cend; ++iter)
	{
		if (*iter == i)
		{
			return true;
		}
	}
	
	return false;
}
