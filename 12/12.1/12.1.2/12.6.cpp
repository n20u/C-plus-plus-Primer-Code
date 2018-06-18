#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>* factory()
{
	return new vector<int>();
}

vector<int>* read(vector<int> *vec)
{
	int i;
	while(cin >> i)
	{
		vec->push_back(i);
	}
	return vec;
}

void print(vector<int> *vec)
{
	cout << "输入完毕。\n结果为：";
	for(auto i : *vec)
	{
		cout << i << " ";
	}
	cout << endl;
	delete vec;
}

int main()
{
	auto vec = factory();
	vec = read(vec);
	print(vec);
	return 0;
}
