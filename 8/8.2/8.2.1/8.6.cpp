#include <iostream>
#include <fstream>
#include "Sales_data.h"

using std::ifstream; using std::ofstream;
using std::cout; using std::cerr; using std::endl;

int main(int argc, char **argv)
{
	ifstream input(argv[1]);
	Sales_data total(input);
	if (!total.isbn().empty())
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}
	return 0;
}
