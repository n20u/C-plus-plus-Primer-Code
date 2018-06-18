#include <iostream>
#include "..\15.2.1\15.3.h"
#include "15.5.h"

using std::cout;

int main() {
	Quote basic("C++ Primer", 128);
	Bulk_quote bulk("C++ Primer Plus", 98, 10, 0.2);
	print_total(cout, basic, 20);
	print_total(cout, bulk, 20);
	return 0;
}
