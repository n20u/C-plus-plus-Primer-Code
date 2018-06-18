#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::regex;
using std::smatch;
using std::regex_search;
using std::sregex_iterator;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::find;

int main() {
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	string text_str;
	vector<string> vec{ "albeit","beige","feint","heir","reign","their",
		"counterfeit","foreign","inveigh","rein","veil","deign",
		"forfeit","inveigle","seize","veineiderdown","freight",
		"leisure","skein","weigheight","heifer","neigh","sleigh",
		"weighteither","height","neighbour","sleight","weirfeign",
		"heinous", "neither", "surfeit", "weird" };
	while (cout << "请输入：" && getline(cin, text_str))
	{
		if (regex_search(text_str, r)) {
			for (sregex_iterator it(text_str.begin(), text_str.end(), r), end_it;
				it != end_it; ++it) {
				if (find(vec.cbegin(), vec.cend(), it->str()) == vec.cend()) {
					auto pos = it->prefix().length();
					pos = pos > 40 ? pos - 40 : 0;
					cout << it->prefix().str().substr(pos)
						<< "\n\t\t>>> " << it->str() << " <<<\n"
						<< it->suffix().str().substr(0, 40) << endl;
				}
				else {
					cout << it->str() << "包含\"ei\"但并非拼写错误。" << endl;
				}
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