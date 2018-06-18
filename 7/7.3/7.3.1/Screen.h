#ifndef SCREEN
#define SCREEN
#include <string>

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
		void some_member() const
		{
			++access_ctr;
		}
		
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		string contents;
		mutable size_t access_ctr;
};
#endif
