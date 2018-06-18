#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	Bulk_quote CP("C++ Primer", 128, 20, 0.2);
	Bulk_quote CPP("C++ Primer Plus", 98, 20, 0.4);
	Bulk_quote Cp(CP);
	cout << endl;
	Bulk_quote cp(std::move(CP));
	cout << endl;
	Bulk_quote Cpp(CPP);
	cout << endl;
	Bulk_quote cpp(std::move(CPP));
	cout << endl;
	return 0;
}
