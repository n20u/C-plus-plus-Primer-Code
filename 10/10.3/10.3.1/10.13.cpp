#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool moreThanFive (const string &s)
{
	return s.size() >= 5;
}

int main()
{
	vector<string> svec;
	cout << "输入10个string：";
	string i;
	cout << endl;
	for (int n = 1; n <= 10; n++)
	{
		cout << n << ":";
		cin >> i;
		svec.push_back(i);
	}
	auto end_partition = partition(svec.begin(), svec.end(), moreThanFive);
	cout << "长度大于等于5的元素：";
	for (auto iter = svec.cbegin(); iter != end_partition; iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
