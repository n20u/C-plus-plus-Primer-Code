#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>

using std::istream; using std::ostream;
using std::string;

struct Sales_data
{
	Sales_data() = default;
	Sales_data(const string &s) : bookNo(s) { }
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(istream &is)
	{
		double price = 0;
		
		is >> bookNo >> units_sold >> price;
		revenue = price * units_sold;
	}

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
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	
	return sum;
}
istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	
	return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " ";
	
	if (item.units_sold != 0)
	    os << item.revenue/item.units_sold;
	else
	    os << "(no sales)";
	    
	return os;
}
#endif
