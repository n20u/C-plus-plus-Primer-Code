#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "输入单词：";
	string word;
	vector<string> words;
	while(cin >> word)
	{
		if(find(words.cbegin(), words.cend(), word) == words.cend())
		{
			words.push_back(word);
		}
	}
	cout << "不重复的单词为：";
	for(const auto &w : words)
	{
		cout << w << " ";
	}
	cout << endl;
	return 0;
}
