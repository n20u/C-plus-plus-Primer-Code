#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include <iostream>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
		Bulk_quote(const Bulk_quote &b) : Disc_quote(b) { std::cout << "Bulk_quote Copy Constructor" << std::endl; }
		Bulk_quote(Bulk_quote &&b) noexcept : Disc_quote(b) { std::cout << "Bulk_quote Move Constructor" << std::endl; }
		Bulk_quote& operator=(const Bulk_quote&);
		Bulk_quote& operator=(Bulk_quote&&) noexcept;
		double net_price(std::size_t) const override;
};

double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= quantity) {
		return cnt * (1 - discount) * price;
	}
	else {
		return cnt * price;
	}
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote &b) {
	std::cout << "Bulk_quote Copy Assignment Operator" << std::endl;
	Disc_quote::operator=(b);
	return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote &&b) noexcept {
	std::cout << "Bulk_quote Move Assignment Operator" << std::endl;
	Disc_quote::operator=(b);
	return *this;
}

#endif
