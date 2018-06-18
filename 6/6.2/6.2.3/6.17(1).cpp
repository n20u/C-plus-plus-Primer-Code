#include <iostream>
#include <iomanip>
#include <string> 

using std::cin; using std::cout; using std::endl;
using std::setw; using std::setfill;
using std::string;

bool isup(const string &s)
{
	auto ret = s.size();
	for (decltype(ret) i = 0; i != s.size(); ++i)
	{
		if (isupper(s[i]))
		{
			return true;
		}
	}
	
	return false;
}

int main()
{
	string s;
	
	cout << "请输入string对象：";
	cin >> s;
	cout << endl << setfill('-') << setw(20) << "" << endl;
	cout << endl <<"该string对象" << (isup(s) ? "含有" : "没有") << "大写字母" <<endl;
	
	return 0;
}
