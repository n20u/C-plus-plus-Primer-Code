#include <iostream>
#include <cstring>

using std::cin; using std::cout; using std::endl;

int main()
{
	const char ca1[] = "A string example";
	const char ca2[] = "A different string";
	
	if (!strcmp(ca1, ca2))
	    cout << "两个string对象相等，都为：" << ca1 << "。" << endl;
	else
	{
		if (strcmp(ca1, ca2) > 0)
		    cout << "两个string对象不相等，小的为：" << ca2 << "，大的为：" << ca1 << "。" << endl;
		else
		    cout << "两个string对象不相等，小的为：" << ca1 << "，大的为：" << ca2 << "。" << endl;
	}
	 
	return 0;
}
