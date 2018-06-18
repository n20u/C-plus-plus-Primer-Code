#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
	string s1 = "A string example";
	string s2 = "A different string";
	
	cout << (s1 == s2 ? "两个string对象相等，都为：" + s1 + "。": s1 > s2 ? "两个string对象不相等，小的为：" + s2 + "，大的为：" + s1 + "。": "两个string对象不相等，小的为：" + s1 + "，大的为：" + s2 + "。") << endl;
	 
	return 0;
}
