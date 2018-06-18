#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include <string>
#include <iostream>
#include "Quote.h"

class Disc_quote : public Quote {
	public:
		Disc_quote() = default;
		Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price),
			quantity(qty), discount(disc) {}
		Disc_quote(const Disc_quote &d) : Quote(d), quantity(d.quantity), discount(d.discount) { std::cout << "Disc_quote Copy Constructor" << std::endl; }
		Disc_quote(Disc_quote &&d) : Quote(d), quantity(std::move(d.quantity)), discount(std::move(d.discount)) { std::cout << "Disc_quote Move Constructor" << std::endl; }
		Disc_quote& operator=(const Disc_quote&);
		Disc_quote& operator=(Disc_quote&&) noexcept;
		double net_price(std::size_t) const = 0;
		void debug() const override final;
	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

void Disc_quote::debug() const {
	Quote::debug();
	std::cout << "\tquantity:" << quantity << "\tdiscount:" << discount << std::endl;
}

Disc_quote& Disc_quote::operator=(const Disc_quote &d) {
	Quote::operator=(d);
	quantity = d.quantity;
	discount = d.discount;
	return *this;
}
Disc_quote& Disc_quote::operator=(Disc_quote &&d) noexcept {
	Quote::operator=(d);
	quantity = std::move(d.quantity);
	discount = std::move(d.discount);
	return *this;
}
#endif
