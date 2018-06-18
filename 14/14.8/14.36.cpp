#include <vector>
#include <string>
#include "ReadString.h"

using std::vector;
using std::string;
using std::cout;

int main() {
	vector<string> svec;
	ReadString readString;
	for(int i = 0; i < 10; ++i)
	{
		svec.push_back(readString());
	}
	cout << "ÊäÈëÎª£º";
	for(const auto s : svec)
	{
		cout << s << " ";
	}
	return 0;
}
