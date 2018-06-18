#include <string>
#include <cstring>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string i;
	cin >> i;
	char *p = new char[i.size()];
	strcpy(p, i.c_str());
	cout << p << endl;
	return 0;
}
