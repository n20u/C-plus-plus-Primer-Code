#include <iostream>

using std::cout;
using std::endl;

template <typename T, unsigned N> void print(const T (&arr)[N]) {
	for (auto elem : arr) {
		cout << elem << " ";
	}
	cout << endl;
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; ++i) {
		arr[i] = i;
	}
	print(arr);
	system("pause");
	return 0;
}