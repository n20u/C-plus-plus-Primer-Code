#include <iostream>
#include "compare.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	int i, j;
	cout << "请输入需要比较的两个数字：";
	cin >> i >> j;
	cout << "比较结果为：" << compare(i, j) << endl;
	system("pause");
	return 0;
}