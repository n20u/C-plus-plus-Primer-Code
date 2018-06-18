#include <string>
#include <regex>
#include <iostream>

using std::string;
using std::regex;
using std::regex_replace;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	string s;
	string fmt = "$2.$5.$7";
	while (getline(cin, s))
	{
		cout << regex_replace(s, r, fmt) << endl;
	}
	system("pause");
	return 0;
}