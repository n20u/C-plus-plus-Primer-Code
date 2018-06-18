#include <iostream>
#include <string>

using std::istream; using std::cout; using std::endl;
using std::string;

istream& func(istream &is)
{
	string buf;
	while (is >> buf)
	{
		cout << buf << endl;
	}
	is.clear();
	return is;
}
