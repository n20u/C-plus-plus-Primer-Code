#include <iostream>
#include <cstring>

using std::cin; using std::cout; using std::endl;

int main()
{
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	char largestr[35];
	
	strcpy (largestr, ca1);
	strcat (largestr, " ");
	strcat (largestr, ca2);
	
	cout << "第一个字符数组为：" << ca1 << "，第二个字符数组为：" << ca2 << "。" << endl << "前两个数组连接后的字符数组为：" << largestr << "。" << endl;
	
	return 0;
}
