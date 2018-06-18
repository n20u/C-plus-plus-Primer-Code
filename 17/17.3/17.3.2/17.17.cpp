#include <string>
#include <regex>
#include <iostream>

using std::string;
using std::regex;
using std::smatch;
using std::regex_search;
using std::sregex_iterator;
using std::cin;
using std::cout;
using std::endl;

int main() {
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	string text_str;
	while (cout << "请输入：" && getline(cin, text_str))
	{
		if (regex_search(text_str, r)) {
			for (sregex_iterator it(text_str.begin(), text_str.end(), r), end_it;
				it != end_it; ++it) {
				cout << it->str() << endl;
			}
		}
		else
		{
			cout << "无单词违反规则。" << endl;
		}
	}
	system("pause");
	return 0;
}