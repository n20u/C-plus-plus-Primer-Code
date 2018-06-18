#include <iostream>
#include "flip.h"

using std::cout;
using std::cin;
using std::endl;

void f(int v1, int &v2) {
	cout << v1 << " " << ++v2 << endl;
}

void g(int &&i, int &j) {
	cout << i << " " << j << endl;
}

int main() {
	int i = 10, j = 20;
	flip(f, i, 42);
	flip(g, j, 42);
	system("pause");
	return 0;
}