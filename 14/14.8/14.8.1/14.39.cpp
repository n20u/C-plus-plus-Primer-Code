#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

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
	int a = 0, b = 0;
	BoundTest boundTest1(2, 8), boundTest2(1, 10);
	while(input >> s)
	{
		if(boundTest1(s)) {
			a++;
		}
		else if(!boundTest2(s)) {
			b++;
		}
	}
	cout << "长度在1至9之间的单词有" << a << "个，长度在10以上的单词有" << b << "个。" << endl;
	return 0;
}
