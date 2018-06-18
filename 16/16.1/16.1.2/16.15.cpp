#include <iostream>
#include "Screen.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	Screen<5, 5> screen;
	cout << "ÇëÊäÈë×Ö·û´®£º";
	cin >> screen;
	cout << "ÊäÈëµÄ×Ö·û´®Îª£º";
	cout << screen << endl;
	system("pause");
	return 0;
}
