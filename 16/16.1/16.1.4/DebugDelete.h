#pragma once
#include <iostream>
#include <typeinfo>

class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) {}
	template<typename T> void operator()(T* p) const {
		os << "deleting unique_ptr"  << std::endl;
		delete p;
	}
private:
	std::ostream & os;
};