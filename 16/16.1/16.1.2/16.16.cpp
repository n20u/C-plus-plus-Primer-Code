#include <iostream>
#include <algorithm>
#include "Vec.h"

using std::cout;
using std::endl;
using std::for_each;

int main() {
	Vec<int> ive({ 1, 2, 3, 4, 5 });
	for_each(ive.begin(), ive.end(), [](const int i) { cout << i << " "; });
	cout << endl;
	system("pause");
	return 0;
}