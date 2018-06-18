#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void elimDups(vector<string> &words) {
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
	sort(words.begin(), words.end());
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
	auto end_unique = unique(words.begin(), words.end());
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
	words.erase(end_unique, words.end());
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
}

bool isShorter(const string&s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	for (const auto &s : words)
	{
		cout << s << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
