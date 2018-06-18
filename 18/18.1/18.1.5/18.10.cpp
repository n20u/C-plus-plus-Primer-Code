#include <iostream>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

void addHaddleError() {
	Sales_data item1, item2, sum;
	while (cin >> item1 >> item2)
	{
		try
		{
			sum = item1 + item2;
		}
		catch (const isbn_mismatch &e)
		{
			cerr << e.what() << "：left isbn(" << e.left
				<< ") right isbn(" << e.right << ")" << endl;
		}
	}
}

void addNotHaddleError() {
	Sales_data item1, item2, sum;
	while (cin >> item1 >> item2)
	{
		sum = item1 + item2;
	}
}

int main() {
	cout << "是否处理异常(1.是；0.否)：";
	int i;
	cin >> i;
	if (i)
	{
		addHaddleError();
	}
	else
	{
		addNotHaddleError();
	}
	system("pause");
	return 0;
}