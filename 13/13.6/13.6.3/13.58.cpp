#include <vector>
#include <algorithm>
#include <iostream>

class Foo
{
	public:
		Foo() = default;
		Foo(const Foo &f) : data(f.data) {}
		Foo sorted() &&;
		Foo sorted() const &;
	private:
		std::vector<int> data;
};

Foo Foo::sorted() const &
{
	std::cout << "const &" << std::endl;
	return Foo(*this).sorted();
}

Foo Foo::sorted() &&
{
	std::cout << "&&" << std::endl;
	sort(data.begin(), data.end());
	return *this;
}

int main()
{
	Foo().sorted();
	Foo f;
	f.sorted();
	return 0;
}
