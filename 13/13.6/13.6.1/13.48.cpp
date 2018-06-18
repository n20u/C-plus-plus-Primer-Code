#include "String.h"
#include <vector>

using std::vector;

int main()
{
	vector<String> sv;
	sv.push_back("C");
	String s("C++");
	sv.push_back(s);
	return 0;
}
