#include "count.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<const char*> cvec{ "C","Java","C++","C++","C++" };
	cout << count("C++", cvec) << endl;
	system("pause");
	return 0;
}