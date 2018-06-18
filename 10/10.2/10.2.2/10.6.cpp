#include <vector>
#include <algorithm>

using std::fill_n;
using std::vector;

int main() {
	vector<int> ivec(10);
	fill_n(ivec.begin(), ivec.size(), 0);
	return 0;
}
