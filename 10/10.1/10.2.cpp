#include <algorithm>
#include <list>
#include <string>
#include <iostream>

using std::count;
using std::list;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
	list<string> sli;
	cout << "输入string序列：";
	string j;
	for (int i = 0; i < 10; i++) {
		cin >> j;
		sli.push_back(j);
	}
	cout << "输入要统计出现次数的string：";
	string i;
	cin >> i;
	cout << i << "在序列中出现的次数为：" << count(sli.cbegin(), sli.cend(), i) << endl;
	system("pause");
	return 0;
}