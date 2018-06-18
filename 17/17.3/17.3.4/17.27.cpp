#include <string>
#include <regex>
#include <iostream>

using std::string;
using std::regex;
using std::regex_replace;
using std::smatch;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string phone = "(\\d{5})(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$1-$2";
	while (getline(cin, s))
	{
		cout << regex_replace(s, r, fmt) << endl;
	}
	system("pause");
	return 0;
}