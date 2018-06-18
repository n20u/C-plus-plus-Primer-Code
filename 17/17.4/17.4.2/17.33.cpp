#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <random>
#include <ctime>

using std::string;
using std::multimap;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::runtime_error;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::time;

multimap<string, string> buildMap(ifstream &map_file)
{
	multimap<string, string> trans_map;
	string key, value;
	while(map_file >> key && getline(map_file, value))
	{
		try
		{
			if(value.size() > 1)
			{
				trans_map.insert({key, value.substr(1)});
			}
			else
			{
				throw runtime_error("no rule for " + key);
			}
		} catch (runtime_error err)
		{
			cout << err.what() << endl;
			continue;
		}
		
	}
	return trans_map;
}

const string& transform(const string &s, const multimap<string, string> &m)
{
	auto map_it = m.find(s);
	if(map_it != m.cend())
	{
		unsigned i = m.count(s);
		default_random_engine e(time(0));
		uniform_int_distribution<unsigned> u(1, i);
		unsigned j = u(e);
		for (unsigned k = 1; k < j; k++)
		{
			++map_it;
		}
		return map_it->second;
	}
	else
	{
		return s;
	}
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while(getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while(stream >> word)
		{
			if(firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main()
{
	ifstream map_file("map_file.txt");
	ifstream input("input.txt");
	word_transform(map_file, input);
	system("pause");
	return 0;
}
