#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>

using std::istream; using std::ostream;
using std::string;

struct Person
{
	friend istream &read(istream&, Person&);
	friend ostream &print(ostream&, Person&);
	
	public:
		Person() = default;
		Person(const string &name, const string &address) : name(name), address(address) { }
		explicit Person(istream &is)
		{
			read(is, *this);
		}
		string getname() const
		{
			return name;
		}
		string getaddress() const
		{
			return address;
		}
	
	private:	
		string name;
		string address;
};

istream &read(istream &is, Person &item)
{
	is >> item.name >> item.address;
	return is;
}
ostream &print(ostream &os, Person &item)
{
	os << item.name << item.address;
	return os;
}

#endif
