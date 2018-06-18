class A
{
public:
	A() = default;
	virtual ~A() = default;
};
class B : public A
{
public:
	B() = default;
	~B() = default;
};
#include <iostream>
#include <string>
#include <typeinfo>
#include "..\..\..\18\18.1\18.1.5\Sales_data.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	int arr[10];
	B b;
	A *p = &b;
	cout << typeid(42).name() << endl
		<< typeid(arr).name() << endl
		<< typeid(Sales_data).name() << endl
		<< typeid(string).name() << endl
		<< typeid(p).name() << endl
		<< typeid(*p).name() << endl;
	system("pause");
	return 0;
}