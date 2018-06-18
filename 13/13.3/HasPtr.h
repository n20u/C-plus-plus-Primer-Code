#include <string>
#include <iostream>

class HasPtr
{
	public:
		friend void swap(HasPtr&, HasPtr&);
		friend bool operator<(const HasPtr&, const HasPtr&);
		HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
		HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
		HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {p.ps = 0;}
		HasPtr& operator=(HasPtr);
		~HasPtr()
		{
			delete ps;
		}
	private:
		std::string *ps;
		int i;
};

HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "call swap(HasPtr&, HasPtr&)" << std::endl;
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	return *lhs.ps < *rhs.ps;
}
