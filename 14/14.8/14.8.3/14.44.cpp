#include <string>
#include <iostream>
#include <map>
#include <functional>
#include <sstream>

using std::string;
using std::map;
using std::function;
using std::plus;
using std::minus;
using std::multiplies;
using std::divides;
using std::modulus;
using std::cin;
using std::cout;
using std::endl;

int main() {
	map<string, function<int(int, int)>> binops = {{"+", plus<int>()}, {"-", minus<int>()},
	{"*", multiplies<int>()}, {"/", divides<int>()}, {"%", modulus<int>()}};
	int i, j;
	string s;
	string line;
	while(cin >> i && cin >> s && cin >> j) {
		cout << binops[s](i, j) << endl;
	}
	return 0;
}
