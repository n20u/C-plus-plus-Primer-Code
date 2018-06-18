#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using std::list;
using std::string;
using std::cout;
using std::endl;

void elimDups(list<string> &words) {
	for (const auto &s : words) {
		cout << s << " ";
	}
	cout << endl;
	words.sort();
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

int main() {
	list<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	elimDups(words);
	return 0;
}
