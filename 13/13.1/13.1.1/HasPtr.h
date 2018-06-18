#include <string>

class HasPtr
{
	public:
		HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
		HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
	private:
		std::string *ps;
		int i;
};
