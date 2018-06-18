#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;

template <typename T, typename U> T my_find(T begin, T end, const U &val) {
	for(; begin != end; ++begin) {
		if (*begin == val) {
			return begin;
		}
	}
	return end;
}

int main() {
	vector<int> ivec{1, 2, 3, 4, 5};
	list<int> ili{1, 2, 3, 4, 5};
	int i;
	cout << "请输入需要查找的数字：";
	cin >> i;
	auto it1 = my_find(ivec.cbegin(), ivec.cend(), i);
	cout << "在vector中的查找结果为：" << (it1 != ivec.cend() ? *it1 : 0) << endl;
	auto it2 = my_find(ili.cbegin(), ili.cend(), i);
	cout << "在list中的查找结果为：" << (it2 != ili.cend() ? *it2 : 0) << endl;
	system("pause");
	return 0;
}