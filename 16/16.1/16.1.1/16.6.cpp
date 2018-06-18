#include <iostream>

using std::cout;
using std::endl;

template<typename T, unsigned N> T* begin(T(&arr)[N]) {
	return arr;
}

template<typename T, unsigned N> T* end(T(&arr)[N]) {
	return arr + N;
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}
	for (auto it = begin(arr); it != end(arr); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}