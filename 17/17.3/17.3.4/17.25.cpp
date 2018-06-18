#include <string>
#include <regex>
#include <iostream>

using std::string;
using std::regex;
using std::regex_search;
using std::smatch;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$2.$5.$7";
	while (getline(cin, s))
	{
		if (regex_search(s, m, r))
		{
			cout << m.prefix() << m.format(fmt) << endl;
		}
	}
	system("pause");
	return 0;
}