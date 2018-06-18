#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
	{
		return str1 == str2;
	}
	
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	
	for (decltype(size) i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
}

int main()
{
	string str1, str2;
	
	cout << "请输入两个string对象：";
	cin >> str1 >> str2;
	
	if (str_subrange(str1, str2))
	{
		cout << "两个string对象相等或其中一个string对象是另一个的子集。" << endl;
	}
	else
	{
		cout << "两个string对象不相等且不为子集。" << endl;
	}
	
	return 0;
}
