#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	char *s1 = "a";
	char *s2 = "b";
	char *p = new char[strlen(s1) + strlen(s2)]();
	strcpy(p, s1);
	strcat(p, s2);
	cout << p << endl;
	delete [] p;
	return 0;
}
