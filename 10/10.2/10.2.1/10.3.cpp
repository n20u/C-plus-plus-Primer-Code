#include <algorithm>
#include <vector>
#include <iostream>

using std::accumulate;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
	vector<int> ivec;
	cout << "输入int序列：";
	int i;
	for ( int j = 0; j < 10; j++ ) {
		cin >> i;
		ivec.push_back(i);
	}
	cout << "元素之和为：" << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;
	system("pause");
	return 0;
} 
