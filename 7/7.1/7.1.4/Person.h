#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>

using std::istream; using std::ostream;
using std::string;

struct Person
{
	Person() = default;
	Person(const string &name, const string &address) : name(name), address(address) { }
	
	string getname() const
	{
		return name;
	}
	string getaddress() const
	{
		return address;
	}
	
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
