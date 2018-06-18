#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int fun()
{
	static int a = 0;
	
	return a++;
}

int main()
{
	string rsp;
	
	do
	{
		cout << fun() << endl << "More? Enter yes or no:";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');
	
	return 0;
}
