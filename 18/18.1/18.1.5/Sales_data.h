#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>
#include <iostream>
#include "library_error.h"

struct Sales_data
{
	friend struct std::hash<Sales_data>;
	friend bool operator==(const Sales_data&, const Sales_data&);
	friend bool operator!=(const Sales_data&, const Sales_data&);
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);
	std::string isbn() const
	{
		return bookNo;
	}
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
	Sales_data& operator+=(const Sales_data&);
	Sales_data& operator=(const std::string&);
	explicit operator std::string() const {
		return bookNo;
	}
	explicit operator double() const {
		return avg_price();
	}
};

double Sales_data::avg_price() const
{
	if (units_sold)
	{
		return revenue/units_sold;
	}
	else
	{
		return 0;
	}
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
	{
		item.revenue = item.units_sold * price;
	}
	else
	{
		item = Sales_data();
	}
	return is;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	if (isbn() != rhs.isbn())
	{
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	}
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data& Sales_data::operator=(const std::string &isbn)
{
	*this = Sales_data(isbn);
	return *this;
}

inline bool operator==(const Sales_data &ls, const Sales_data &rs)
{
	return ls.bookNo == rs.bookNo && ls.units_sold == rs.units_sold && ls.revenue == rs.revenue;
}
inline bool operator!=(const Sales_data &ls, const Sales_data &rs)
{
	return !(ls == rs);
}

#endif
