#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

int main()
{
	string str("ab2c3d7R4E6");
	string numbers("0123456789");
	string str1("abcdefghijklmnopqrstuvwxyz");
	string str2(str1);
	for (auto &c : str2)
	{
		c = toupper(c);
	}
	string alphabet = str1 + str2;
	cout << "×ÖÄ¸×Ö·ûÎª£º";
	for (string::size_type pos = 0; pos < str.size(); ++pos)
	{
		pos = str.find_first_not_of(numbers, pos);
		if (pos != string::npos)
		{
			cout << str[pos] << " ";
		}
		else
		{
			break;
		}
	}
	cout << endl;
	cout << "Êý×Ö×Ö·ûÎª£º";
	for (string::size_type pos = 0; pos < str.size(); ++pos)
	{
		pos = str.find_first_not_of(alphabet, pos);
		if (pos != string::npos)
		{
			cout << str[pos] << " ";
		}
		else
		{
			break;
		}
	}
	cout << endl;
	
	return 0;
}
