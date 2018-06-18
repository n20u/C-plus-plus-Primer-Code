#include <iostream>
#include <string>

using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{
	string s, s1;
	
	cin >> s;
	
	while (cin >> s1)
	    s = s + " " + s1;
	
	cout << s << endl;
	
	return 0;
}
