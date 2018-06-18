#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::stable_sort;
using std::find_if;
using std::for_each;
using std::ostream;
using std::cout;
using std::endl;

struct ShorterString {
	bool operator()(const string &s1, const string &s2) const {
		return s1.size() < s2.size();
	}
};

class ShortestLength {
	public:
		ShortestLength(vector<string>::size_type sz) : sz(sz) {}
		bool operator()(const string &a) {
			return a.size() >= sz;
		}
	private:
		vector<string>::size_type sz;
};

class PrintString {
	public:
		PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) {}
		void operator()(const string &s) const {
			os << s << sep;
		}
	private:
		ostream &os;
		char sep;
};

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), ShorterString());
	auto wc = find_if(words.begin(), words.end(), ShortestLength(sz));
	auto count = words.end() - wc;
	cout << count << " " << (count > 1 ? "words" : "word") << " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(), PrintString());
	cout << endl;
}

int main() {
	vector<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	biggies(words, 5);
	return 0;
}
