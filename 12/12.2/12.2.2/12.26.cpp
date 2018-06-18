#include <string>
#include <memory>
#include <iostream>

using std::string;
using std::allocator;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n = 10;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	auto q = p;
	while(cin >> s && q != p + n)
	{
		alloc.construct(q++, s);
	}
	while(q != p)
	{
		alloc.destroy(--q);
	}
	alloc.deallocate(p, n);
	return 0;
}
