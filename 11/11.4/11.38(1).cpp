#include <unordered_map>
#include <string>
#include <iostream>

using std::unordered_map;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	unordered_map<string, size_t> word_count;
	string word;
	while(cin >> word)
	{
		++word_count[word];
	}
	for(const auto &w : word_count)
	{
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
	}
	return 0;
}
