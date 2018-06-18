#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::array;
using std::fill;

class BoundTest {
	public:
		BoundTest(size_t lower, size_t upper) : lower(lower), upper(upper) {}
		bool operator()(string s) {
			return s.size() >= lower && s.size() <= upper;
		}
	private:
		size_t lower;
		size_t upper;
};

int main() {
	ifstream input("Text.txt");
	string s;
	array<int, 10> ia;
	fill(ia.begin(), ia.end(), 0);
	while(input >> s)
	{
		for(int i = 0; i < 10; i++)
		{
			BoundTest boundTest(i + 1, i + 1);
			if(boundTest(s))
			{
				++ia[i];
				break;
			}
		}
	}
	for(int i = 0; i < 10; ++i) {
		cout << "长度为" << i + 1 << "的单词有" << ia[i] << "个。" << endl;
	}
	return 0;
}
