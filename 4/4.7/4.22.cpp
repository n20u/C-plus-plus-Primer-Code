#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
	float grade;
	
	cout << "ÇëÊäÈë³É¼¨£º";
	cin >> grade;
	cout << (grade > 90 ? "high pass" : grade > 75 ? "pass" : grade < 60 ? "fail" : "low pass") << endl;
	
	return 0;
}
