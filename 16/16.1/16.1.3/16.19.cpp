#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<typename T>
void printT(const T& container) {
	using size_type = typename T::size_type;
	for (size_type i = 0; i < container.size(); ++i) {
		cout << container[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> ivec{ 1, 2, 3, 4, 5 };
	printT(ivec);
	system("pause");
	return 0;
}