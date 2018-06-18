#ifndef ANDQUERY_H
#define ANDQUERY_H

#include <memory>
#include <algorithm>
#include "Query.h"
#include "BinaryQuery.h"
#include "..\15.9.3\Query_base.h"
#include "..\15.9.3\TextQuery.h"
#include "..\15.9.3\QueryResult.h"

class AndQuery: public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery &text) const {
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

#endif
