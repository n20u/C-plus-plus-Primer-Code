#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::placeholders::_1;

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

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b){ return a.size() < b.size(); });
	auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
	auto count = wc - words.begin();
	cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz << " or longer" << endl;
	for_each(words.begin(), wc, [](const string &s){cout << s << " ";});
	cout << endl;
}

int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	biggies(words, 5);
	return 0;
}
