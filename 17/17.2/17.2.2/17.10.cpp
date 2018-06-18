#include <bitset>
#include <iostream>

using std::bitset;
using std::cout;
using std::endl;

int main() {
	int a[]{ 1,2,3,5,8,13,21 };
	bitset<32> bit1;
	for (const auto i : a) {
		bit1.set(i);
	}
	bitset<32> bit2;
	for (size_t i = 0; i < bit1.size(); ++i) {
		bit2[i] = bit1[i];
	}
	cout << bit1 << endl << bit2 << endl;
	system("pause");
	return 0;
}