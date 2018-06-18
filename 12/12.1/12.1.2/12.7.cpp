#include <iostream>
#include <vector>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

shared_ptr<vector<int>> factory()
{
	return make_shared<vector<int>>();
}

shared_ptr<vector<int>> read(shared_ptr<vector<int>> vec)
{
	int i;
	while(cin >> i)
	{
		vec->push_back(i);
	}
	return vec;
}

void print(shared_ptr<vector<int>> vec)
{
	cout << "输入完毕。\n结果为：";
	for(auto i : *vec)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	auto vec = factory();
	vec = read(vec);
	print(vec);
	return 0;
}
