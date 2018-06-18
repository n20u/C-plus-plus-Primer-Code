#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;

int main()
{
	int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int cnt;
	
	cout << "请输入十二个用于初始化二维数组的整数：";
	
	for (auto row = begin(ia); row != end(ia); ++row)
	    for (auto col = begin(*row); col != end(*row); ++col)
	    {
	    	cin >> cnt;
	    	*col = cnt;
		}
				
	cout << "二维数组为：";
	
	for (auto row = begin(ia); row != end(ia); ++row)
	{
		for (auto col = begin(*row); col != end(*row); ++col)
	    	cout << *col << " ";
	    cout << endl;
	}
	
	return 0;
}
