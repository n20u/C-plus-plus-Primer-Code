#include <iostream>
#include "errorMsg.h"

using std::cerr;
using std::cout;
using std::endl;

int main() {
	errorMsg(cerr, 1, 'a', "C++");
	cout << endl;
	system("pause");
	return 0;
}