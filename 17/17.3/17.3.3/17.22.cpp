#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::vector;
using std::string;
using std::regex;
using std::smatch;
using std::regex_search;
using std::sregex_iterator;

struct PersonInfo
{
	string name;
	string phones;
};

bool valid(const smatch &m) {
	if (m[1].matched) {
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else {
		return !m[3].matched && m[4].str() == m[6].str();
	}
}

string format(const smatch &m)
{
	return m[2].str() + "-" + m[5].str() + "-" + m[7].str();
}

int main()
{
	string line, word;
	vector<PersonInfo> people;
	for (int i = 0; i < 3; ++i)
	{
		getline(cin, line);
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		getline(record, info.phones);
		people.push_back(info);
	}
	string phone = "(\\()?(\\d{3})(\\))?([[:blank:]]*)?(\\d{3})([[:blank:]]*)?(\\d{4})";
	regex r(phone);
	smatch m;
	for (const auto &entry : people)
	{
		ostringstream formatted, badNums;
		if (regex_search(entry.phones, r)) {
			for (sregex_iterator it(entry.phones.begin(), entry.phones.end(), r), end_it;
				it != end_it; ++it)
			{
				if (valid(*it))
				{
					formatted << format(*it);
				}
				else
				{
					badNums << entry.phones;
				}
			}
		}
		else
		{
			badNums << entry.phones;
		}
		if (badNums.str().empty())
		{
			cout << entry.name << " " << formatted.str() << endl;
		}
		else
		{
			cerr << "input error:" << entry.name << ",invalid number(s):" << badNums.str() << endl;
		}
	}
	system("pause");
	return 0;
}
