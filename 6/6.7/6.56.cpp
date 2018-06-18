#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include "Fpvec.h"
#include "6.55.cpp"

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::runtime_error; using std::range_error; using std::out_of_range;
using std::setw; using std::setfill;

int main()
{
	func();
	int a = 0, b = 0, i;
	
	cout << "请输入要处理的两个整数：\na = ";
	cin >> a;
	cout << "b = ";
	while (cin >> b)
	{
		cout << "请输入要执行的操作对应的数字【加（1）、减（2）、乘（3）、除（4）】：";
		
		while (cin >> i)
		{
			try
			{
				if (i < 1 || i > 4)
				{
					throw out_of_range("输入的操作不存在！");
				}
				else if (i == 4 && b == 0)
				{
					throw range_error("除数不能为零！");
				}
				else
				{
					break;
				}
			} catch (out_of_range err)
			{
				cout << err.what() << "\n重试？输入 y 或 n" << endl;
				
				char c;
				
				cin >> c;
				
				if (!cin || c != 'y')
				{
					return -1;
				}
				else
				{
					cout << "请输入要执行的操作对应的数字【加（1）、减（2）、乘（3）、除（4）】：";
				}
			} catch (range_error err1)
			{
				cout << err1.what() << "\n请输入要执行的操作对应的数字【重新输入操作（1）、重新输入除数（2）、直接退出程序（3）】：";
				int j;
				
				while (cin >> j)
				{
					try
					{
						if (j < 1 || j > 3)
						{
							throw runtime_error("输入的操作不存在！");
						}
						else
						{
							break;
						}
					} catch (runtime_error err2)
					{
						cout << err2.what() << "\n重试？输入 y 或 n" << endl;
				
						char c;
						
						cin >> c;
						
						if (!cin || c != 'y')
						{
							return -1;
						}
					}
				}
				if (j == 1)
				{
					cout << "请输入要执行的操作对应的数字【加（1）、减（2）、乘（3）、除（4）】：";
					continue;
				}
				else if (j == 2)
				{
					cout << "b = ";
					while (cin >> b)
					{
						try
						{
							if (b == 0)
							{
								throw runtime_error("输入的除数仍为零！");
							}
							else
							{
								break;
							}
						} catch (runtime_error err3)
						{
							cout << err3.what() << "\n重试？输入 y 或 n" << endl;
					
							char c;
							
							cin >> c;
							
							if (!cin || c != 'y')
							{
								return -1;
							}
						}
					}
					break; 
				}
				else
				{
					return 1;
				}
			}
		}
	    break;
    }
	cout << setfill('-') << setw(20) << "" << endl;
	cout << "a ";
	
	switch (i)
	{
		case 1:
			cout << '+';
			break;
		case 2:
			cout << '-';
			break;
		case 3:
			cout << '*';
			break;
		case 4:
			cout << '/';
			break;
	}
	
	cout << " b =" << Fpvec[i - 1](a, b) << endl;
	
	return 0;
}
