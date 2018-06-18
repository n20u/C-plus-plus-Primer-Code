#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
	cout << "输入整数序列：";
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> ivec;
	copy(in_iter, eof, back_inserter(ivec));
	sort(ivec.begin(), ivec.end());
	cout << "排序后的结果为：";
	copy(ivec.begin(), ivec.end(), out_iter);
	return 0;
}
