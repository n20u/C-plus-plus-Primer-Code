#include <iostream>
#include <string>

using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{
	string s1, s2;
	
	cin >> s1 >> s2;
	
	if (s1.size() == s2.size())
	    cout << "两个字符串等长，都是：" << s1 << endl;
	else
	{
		string s;
		
		s = s1.size() > s2.size() ? s1 : s2;
		
		cout << "两个字符串不等长，长度较大的字符串是：" << s << endl;
	}
	 
	return 0;
}
