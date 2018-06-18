#include <iostream>
#include "Sales_data.h"

using std::cin; using std::cout; using std::cerr; using std::endl;

int main()
{
	Sales_data total;
	double price = 0;
	
	if (cin >> total.bookNo >> total.units_sold >> price)
	{
		total.revenue = total.units_sold * price;
	    
	    Sales_data trans;
	    
	    while(cin >> trans.bookNo >> trans.units_sold >> price)
	    {
	    	trans.revenue = trans.units_sold * price;
	    	
			if (total.isbn() == trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				cout << total.isbn() << " " << total.units_sold << " " << total.revenue << " ";
				if (total.units_sold != 0)
				    cout << total.revenue/total.units_sold << endl;
				else
				    cout << "(no sales)" << endl;
				
				total = trans;
			}
		}
		
		cout << total.isbn() << " " << total.units_sold << " " << total.revenue << " ";
		if (total.units_sold != 0)
		    cout << total.revenue/total.units_sold << endl;
		else
		    cout << "(no sales)" << endl;
		
		return 0;
	}
	else
	{
		cerr << "No data?!";
		return -1;
	}
}
