#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::pair;

int main()
{
	map<string, vector<pair<string, int>>> family;
	string line;
	while(getline(cin, line))
	{
		string surname, name;
		int birthday;
		istringstream record(line);
		record >> surname;
		while(record >> name && record >> birthday)
		{
			family[surname].push_back(make_pair(name, birthday));
		}
	}
	cout << "定义的map如下：" << endl;
	for(const auto &f : family)
	{
		cout << f.first << " ";
		for(const auto &s : f.second)
		{
			cout << s.first << " " << s.second << " ";
		}
		cout << endl;
	}
	return 0;
} 
