#include <iostream>

int main()
{
	std::cout << "输入两个整数：";
	
	int i = 0, j = 0;
	
	std::cin >> i >> j;
	
	if (i >= j)
	{
		while (i >= j)
		{
		std::cout << i-- << " ";
		}
	}
	else
	{
		while (i <= j)
		{
			std::cout << i++ << " ";
		}
	}
	
	return 0;
} 
