#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
	string rsp;
	
	do
	{
		cout << "please enter two string:";
		
		string str1, str2;
		
		cin >> str1 >> str2;
		cout << "The shorter of " << str1 << " and " << str2 << " is " << (str1.size() < str2.size() ? str1 : str2) << endl << "More? Enter yes or no:";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');
	
	return 0;
}
