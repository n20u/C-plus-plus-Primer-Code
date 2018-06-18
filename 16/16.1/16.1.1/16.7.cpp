#include <iostream>

using std::cout;
using std::endl;

template<typename T, unsigned N> constexpr unsigned sizeOfArray(T(&arr)[N]) {
	return N;
}

int main() {
	int arr[10];
	cout << "数组大小为：" << sizeOfArray(arr) << endl;
	system("pause");
	return 0;
}