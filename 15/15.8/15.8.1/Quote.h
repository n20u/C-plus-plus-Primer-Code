#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote {
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
		Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) { std::cout << "Quote Copy Constructor" << std::endl; }
		Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { std::cout << "Quote Move Constructor" << std::endl; }
		Quote& operator=(const Quote&);
		Quote& operator=(Quote&&) noexcept;
		virtual Quote* clone() const & {
			return new Quote(*this);
		}
		virtual Quote* clone() && {
			return new Quote(std::move(*this));
		}
		std::string isbn() const {
			return bookNo;
		}
		virtual double net_price(std::size_t n) const {
			return n * price;
		}
		virtual void debug() const {
			std::cout << "data member:\n\tbookNo:" << bookNo << "\tprice:" << price << std::endl;
		}
		virtual ~Quote() = default;
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};

Quote& Quote::operator=(const Quote &q) {
	std::cout << "Quote Copy Assignment Operator" << std::endl;
	bookNo = q.bookNo;
	price = q.price;
	return *this;
}

Quote& Quote::operator=(Quote &&q) noexcept {
	std::cout << "Quote Move Assignment Operator" << std::endl;
	bookNo = std::move(q.bookNo);
	price = std::move(q.price);
	return *this;
}

#endif
