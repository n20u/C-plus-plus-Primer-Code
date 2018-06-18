#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

using std::string;

struct Sales_data
{
	string isbn() const
	{
		return bookNo;
	}
	Sales_data& combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

#endif
