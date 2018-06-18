#include <algorithm>
#include <vector>
#include <iostream>

using std::count;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<int> ivec;
	cout << "输入int序列：";
	for (int i = 0, j; i < 10; i++) {
		cin >> j;
		ivec.push_back(j);
	}
	cout << "输入要统计出现次数的值：";
	int i;
	cin >> i;
	cout << i << "在序列中出现的次数为：" << count(ivec.cbegin(), ivec.cend(), i) << endl;
	system("pause");
	return 0;
}