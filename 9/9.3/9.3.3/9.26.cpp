#include <iostream>
#include <vector>
#include <list>

using std::cout; using std::endl;
using std::vector;
using std::list;

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> ivec;
	list<int> ili;
	for (const auto &num : ia)
	{
		ivec.push_back(num);
		ili.push_back(num);
	}
	auto iter1 = ivec.begin();
	while (iter1 != ivec.end())
	{
		if (*iter1 % 2)
		{
			++iter1;
		}
		else
		{
			iter1 = ivec.erase(iter1);
		}
	}
	cout << "vector中的元素为：";
	for (const auto &num : ivec)
	{
		cout << num << " ";
	}
	cout << endl;
	auto iter2 = ili.begin();
	while (iter2 != ili.end())
	{
		if (*iter2 % 2)
		{
			iter2 = ili.erase(iter2);
		}
		else
		{
			++iter2;
		}
	}
	cout << "list中的元素为：";
	for (const auto &num : ili)
	{
		cout << num << " ";
	}
	cout << endl;
	return 0;
}
