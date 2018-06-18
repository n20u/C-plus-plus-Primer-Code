#ifndef ANDQUERY_H
#define ANDQUERY_H

#include <algorithm>
#include <memory>
#include <iterator>
#include "Query1.h"
#include "BinaryQuery1.h"
#include "Query_base.h"
#include "..\15.9.3\TextQuery.h"
#include "..\15.9.3\QueryResult.h"

class AndQuery: public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const;
	AndQuery* clone() const override {
		return new AndQuery(*this);
	}
};

inline Query operator&(const Query &lhs, const Query &rhs) {
	return new AndQuery(lhs, rhs);
}

QueryResult AndQuery::eval(const TextQuery &text) const {
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

#endif
