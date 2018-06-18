#include <iostream>
#include <string>

using std::string;
using std::cin; using std::cout; using std::endl;

int main()
{
	string s1, s2;
	
	cin >> s1 >> s2;
	
	if (s1 == s2)
	    cout << "两个字符串相等，都是：" << s1 << endl;
	else
	{
		string s;
		
		s = s1 > s2 ? s1 : s2;
		
		cout << "两个字符串不相等，较大的字符串是：" << s << endl;
	}
	 
	return 0;
}
