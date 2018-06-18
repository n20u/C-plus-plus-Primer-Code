#ifndef PERSON
#define PERSON
#include <string>

using std::string;

struct Person
{
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

#endif
