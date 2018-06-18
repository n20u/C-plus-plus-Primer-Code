#include <string>
#include <iostream>
#include "Quote.h"

class Monu_quote : public Quote {
	public:
		Monu_quote() = default;
		Monu_quote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), max_qty(qty), discount(disc) {}
		double net_price(std::size_t) const override;
		void debug() const override;
	private:
		std::size_t max_qty = 0;
		double discount = 0.0;
};

double Monu_quote::net_price(std::size_t cnt) const {
	if (cnt <= max_qty) {
		return cnt * (1 - discount) * price;
	}
	else {
		return cnt * price;
	}
}

void Monu_quote::debug() const {
	Quote::debug();
	std::cout << "\tmax_qty:" << max_qty << "\tdiscount" << discount << std::endl;
}
