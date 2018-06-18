#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
	vector<int> ivec;
	cout << "请选择提取vector中的第一个元素的方式[at(1)、下标运算符(2)、front(3)、begin(4)]:";
	int i = 0;
	cin >> i;
	switch (i)
	{
		case 1:
			cout << ivec.at(0);
			break;
		case 2:
			cout << ivec[0];
			break;
		case 3:
			cout << *ivec.begin();
			break;
		case 4:
			cout << ivec.front();
			break;
		default:
			cout << "您选择的操作不存在！";
	}
	return 0;
}
