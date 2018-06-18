#include <iostream>
#include <string>
#include "9.46.cpp"

using std::cout; using std::endl;
using std::string;

int main()
{
	string name = "abc";
	string pre = "Mr.";
	string su = "Jr.";
	name = func(name, pre, su);
	cout << name << endl;
	return 0;
}
