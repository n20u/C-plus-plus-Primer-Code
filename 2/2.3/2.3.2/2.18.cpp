#include <iostream>

int main()
{
	int i = 42, j = 24, *p = &i;
	
	p = &j;//更改指针的值 
	*p = 42;//更改指针所指对象的值
	
	return 0; 
} 
