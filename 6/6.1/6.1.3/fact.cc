#include <iostream>
#include "E:\C¡¢C++\C++ Primer\6\6.1\6.1.2\Chapter6.h"

using std::cin; using std::cout; using std::endl;

int fact(int val)
{
	int ret = 1;
	
	while (val > 1)
	{
		ret *= val--;
	}
	
	return ret;
}
