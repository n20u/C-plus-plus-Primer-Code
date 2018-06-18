#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<typename T>
void printT(const T& container) {
	for (auto i = container.begin(); i != container.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

int main() {
	vector<int> ivec{ 1, 2, 3, 4, 5 };
	printT(ivec);
	system("pause");
	return 0;
}