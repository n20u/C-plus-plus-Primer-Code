#include <string>
#include <regex>
#include <iostream>

using std::string;
using std::regex;
using std::smatch;
using std::sregex_iterator;
using std::cin;
using std::cout;
using std::endl;

bool valid(const smatch &m) {
	if (m[1].matched) {
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else {
		return !m[3].matched && m[4].str() == m[6].str();
	}
}

int main() {
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	while (getline(cin, s)) {
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
			if (valid(*it)) {
				cout << "valid:" << it->str() << endl;
			}
			else {
				cout << "not valid:" << it->str() << endl;
			}
		}
	}
	system("pause");
	return 0;
}