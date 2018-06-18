#include <string>
#include <cstring>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string s1 = "a";
	string s2 = "b";
	char *p = new char[s1.size() + s2.size()]();
	strcpy(p, (s1 + s2).c_str());
	cout << p << endl;
	return 0;
}
