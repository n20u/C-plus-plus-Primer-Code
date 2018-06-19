#pragma once
#include <string>
#include <utility>
#include "Sales_data.h"

class Token
{
public:
	Token() : tok(INT), ival(0) { }
	Token(const Token &t) : tok(t.tok) { copyUnion(t);  }
	Token(Token &&t) noexcept : tok(std::move(t.tok)) { moveUnion(std::move(t)); }
	Token &operator=(const Token&);
	~Token() {
		if (tok == STR)
		{
			sval.std::string::~string();
		}
		else if (tok == SALES)
		{
			sales.~Sales_data();
		}
	}
	Token &operator=(const std::string&);
	Token &operator=(char);
	Token &operator=(int);
	Token &operator=(double);
	Token &operator=(const Sales_data&);

private:
	enum {INT, CHAR, DBL, STR, SALES} tok;
	union
	{
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sales;
	};
	void copyUnion(const Token&);
	void moveUnion(Token &&);
};

void Token::copyUnion(const Token &t) {
	switch (t.tok)
	{
	case Token::INT: ival = t.ival;
		break;
	case Token::CHAR: cval = t.cval;
		break;
	case Token::DBL: dval = t.dval;
		break;
	case Token::STR: new(&sval) std::string(t.sval);
		break;
	case Token::SALES: new(&sales) Sales_data(t.sales);
		break;
	}
}

void Token::moveUnion(Token &&t) {
	switch (t.tok)
	{
	case Token::INT: ival = std::move(t.ival);
		break;
	case Token::CHAR: cval = std::move(t.cval);
		break;
	case Token::DBL: dval = std::move(t.dval);
		break;
	case Token::STR: new(&sval) std::string(std::move(t.sval));
		break;
	case Token::SALES: new(&sales) Sales_data(std::move(t.sales));
		break;
	}
}

Token &Token::operator=(const Token &t) {
	if (tok == STR && t.tok != STR)
	{
		sval.std::string::~string();
	}
	if (tok == STR && t.tok == STR)
	{
		sval = t.sval;
	}
	if (tok == SALES && t.tok != SALES)
	{
		sales.~Sales_data();
	}
	if (tok == SALES && t.tok == SALES)
	{
		sales = t.sales;
	}
	else
	{
		copyUnion(t);
	}
	tok = t.tok;
	return *this;
}

Token &Token::operator=(const std::string &s) {
	if (tok == SALES)
	{
		sales.~Sales_data();
	}
	if (tok == STR)
	{
		sval = s;
	}
	else
	{
		new(&sval) std::string(s);
	}
	tok = STR;
	return *this;
}

Token &Token::operator=(char c) {
	if (tok == STR)
	{
		sval.std::string::~string();
	}
	else if (tok == SALES)
	{
		sales.~Sales_data();
	}
	cval = c;
	tok = CHAR;
	return *this;
}

Token &Token::operator=(int i) {
	if (tok == STR)
	{
		sval.std::string::~string();
	}
	else if (tok == SALES)
	{
		sales.~Sales_data();
	}
	ival = i;
	tok = INT;
	return *this;
}

Token &Token::operator=(double d) {
	if (tok == STR)
	{
		sval.std::string::~string();
	}
	else if (tok == SALES)
	{
		sales.~Sales_data();
	}
	dval = d;
	tok = DBL;
	return *this;
}

Token &Token::operator=(const Sales_data &sa) {
	if (tok == STR)
	{
		sval.std::string::~string();
	}
	if (tok == SALES)
	{
		sales = sa;
	}
	else
	{
		new(&sales) Sales_data(sa);
	}
	tok = SALES;
	return *this;
}