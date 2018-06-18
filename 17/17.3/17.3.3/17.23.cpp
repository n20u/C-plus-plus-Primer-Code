#include <string>
#include <regex>
#include <iostream>

using std::string;
using std::regex;
using std::sregex_iterator;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string postcode = "(\\d{5})(-)?(\\d{4})?";
	regex r(postcode);
	string s;
	while (getline(cin, s)) {
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
			cout << it->str() << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}