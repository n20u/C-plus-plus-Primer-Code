#include <map>
#include <set> 
#include <string>
#include <iostream>

using std::multimap;
using std::map;
using std::set;
using std::string;
using std::cout;
using std::endl;

int main()
{
	multimap<string, string> authors{{"a", "A"}, {"a", "B"}, {"b", "C"}, {"b", "D"}, {"c", "E"}, {"c", "F"}};
	map<string, set<string>> other_authors;
	for(const auto &w : authors)
	{
		other_authors[w.first].insert(w.second);
	}
	for(const auto &i : other_authors)
	{
		cout << i.first << " ";
		for(const auto &j : i.second)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
} 
