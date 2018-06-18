#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

template<typename T> void f(T t) {
	cout << "第一个void f(" << typeid(T).name() << ")" << endl;
}
template<typename T> void f(const T *t) {
	cout << "第二个void f(const " << typeid(T).name() << "*)" << endl;
}
template<typename T> void g(T t) {
	cout << "第一个void g(" << typeid(T).name() << ")" << endl;
}
template<typename T> void g(T *t) {
	cout << "第二个void g(" << typeid(T).name() << "*)" << endl;
}

int main() {
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42); g(p); g(ci); g(p2);
	f(42); f(p); f(ci); f(p2);
	system("pause");
	return 0;
}