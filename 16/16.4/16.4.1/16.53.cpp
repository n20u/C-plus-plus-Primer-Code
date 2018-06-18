#include <iostream>
#include "print.h"

using std::cout;
using std::endl;

int main() {
	int i = 1;
	long j = 2;
	float k = 3;
	double l = 4;
	char a = 'a';
	print(cout, i);
	cout << endl;
	print(cout, i, j);
	cout << endl;
	print(cout, i, j, k, l, a);
	cout << endl;
	system("pause");
	return 0;
}
