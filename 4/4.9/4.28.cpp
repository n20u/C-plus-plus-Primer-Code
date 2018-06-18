#include <iostream>

using std::cout; using std::endl;

int main()
{
	cout << "bool类型所占空间的大小为：" << sizeof(bool) << endl;
	cout << "char类型所占空间的大小为：" << sizeof(char) << endl;
	cout << "wchar_t类型所占空间的大小为：" << sizeof(wchar_t) << endl;
	cout << "char16_t类型所占空间的大小为：" << sizeof(char16_t) << endl;
	cout << "char32_t类型所占空间的大小为：" << sizeof(char32_t) << endl;
	cout << "short类型所占空间的大小为：" << sizeof(short) << endl;
	cout << "int类型所占空间的大小为：" << sizeof(int) << endl;
	cout << "long类型所占空间的大小为：" << sizeof(long) << endl;
	cout << "long long类型所占空间的大小为：" << sizeof(long long) << endl;
	cout << "float类型所占空间的大小为：" << sizeof(float) << endl;
	cout << "double类型所占空间的大小为：" << sizeof(double) << endl;
	cout << "long double类型所占空间的大小为：" << sizeof(long double) << endl;
	
	return 0;
}
