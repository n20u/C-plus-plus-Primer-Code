#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::endl;
using std::ifstream; using std::ofstream;
using std::istringstream; using std::ostringstream;
using std::vector;
using std::string;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

bool valid(const string &nums)
{
	return isdigit(nums[0]);
}

string format(const string &nums)
{
	return nums.substr(0, 3) + "-" + nums.substr(3, 3) + "-" + nums.substr(6);
}

int main(int argc, char**argv)
{
	ifstream is(argv[1]);
	ofstream os(argv[2]);
	if (!is)
	{
		os << "No data?!";
		return -1;
	}
	
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(is, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	for (const auto &entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones)
		{
			if (!valid(nums))
			{
				badNums << " " << nums;
			}
			else
			{
				formatted << " " << format(nums);
			}
			if (badNums.str().empty())
			{
				os << entry.name << " " << formatted.str() << endl;
			}
			else
			{
				os << "input error: " << entry.name << "invalid number(s) " << badNums.str() << endl;
			}
		}
	}
	return 0;
}
