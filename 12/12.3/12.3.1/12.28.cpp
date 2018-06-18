#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using std::vector;
using std::map;
using std::set;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::ifstream;

int main()
{
	int n = 0;
	ifstream in("Text.txt");
	string line;
	vector<string> text;
	map<string, set<int>> content;
	while(getline(in, line))
	{
		text.push_back(line);
		n++;
		istringstream s(line);
		string word;
		while(s >> word)
		{
			content[word].insert(n);
		}
	}
	while(true)
	{
		cout << "请输入您需要查找的单词：";
		string word;
		cin >> word;
		if(content.find(word) == content.end())
		{
			cout << word << "is not in the text." << endl; 
		}
		else
		{
			cout << word << (content.find(word)->second.size() > 1 ? " occurs " : " occur ") << content.find(word)->second.size() << (content.find(word)->second.size() > 1 ? " times" : " time") << endl;
			for(const auto w : content.find(word)->second)
			{
				cout << "(line " << w << ") " << text[w] << endl;
			}
		}
		string mark;
		cout << "您还想继续吗？yes or no" << endl;
		cin >> mark;
		if(mark != "yes")
		{
			break;
		}
	}
	return 0;
}
