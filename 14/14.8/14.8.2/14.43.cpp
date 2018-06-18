#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using std::vector;
using std::modulus;
using std::any_of;
using std::cout;

int main() {
	vector<int> ivec{2, 4, 6, 8, 10};
	auto mark = any_of(ivec.begin(), ivec.end(), [](int i){return 0 == modulus<int>()(2, i);});
	cout << (mark ? "Yes" : "No");
	return 0;
}
