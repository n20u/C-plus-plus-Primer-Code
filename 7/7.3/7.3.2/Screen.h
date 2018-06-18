#ifndef SCREEN
#define SCREEN
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::istream; using std::ostream;
using std::string;

class Screen
{
	public:
		using pos = string::size_type;
		Screen() = default;
		Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
		Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
		char get() const
		{
			return contents[cursor];
		}
		char get(pos ht, pos wd) const
		{
			pos row = ht * width;
			return contents[row + wd];
		}
		Screen &move(pos ht, pos wd)
		{
			pos row = ht * width;
			cursor = row + wd;
			return *this;
		}
		Screen &set(char c)
		{
			contents[cursor] = c;
			return *this;
		}
		Screen &set(pos ht, pos wd, char c)
		{
			contents[ht * width + wd] = c;
			return *this;
		}
		Screen &display(ostream &os)
		{
			do_display(os);
			return *this;
		}
		const Screen &display(ostream &os) const
		{
			do_display(os);
			return *this;
		}
		void some_member() const
		{
			++access_ctr;
		}
		
	private:
		void do_display(ostream &os) const
		{
			os << contents;
		}
		pos cursor = 0;
		pos height = 0, width = 0;
		string contents;
		mutable size_t access_ctr;
};
#endif
