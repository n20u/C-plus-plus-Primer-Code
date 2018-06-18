#include <algorithm>
#include <vector>
#include <iostream>

using std::vector;
using std::replace_if;
using std::cout;

class IsEqual {
	public:
		IsEqual(int i) : value(i) {}
		bool operator()(int elem) const {
			return elem == value;
		}
	private:
		int value;
};

int main() {
	vector<int> ivec{3, 1, 4, 1, 5, 9, 2, 6, 5};
	for(const auto &i : ivec)
	{
		cout << i << " ";
	}
	cout << "\n2->5£º\n";
	replace_if(ivec.begin(), ivec.end(), IsEqual(2), 5);
	for(const auto &i : ivec)
	{
		cout << i << " ";
	}
	return 0;
} 
