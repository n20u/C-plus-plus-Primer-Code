#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include <string>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
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

#endif
