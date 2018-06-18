#ifndef ORQUERY_H
#define ORQUERY_H

#include <memory>
#include "Query1.h"
#include "BinaryQuery1.h"
#include "Query_base.h"
#include "..\15.9.3\TextQuery.h"
#include "..\15.9.3\QueryResult.h"

class OrQuery: public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right): BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
	OrQuery* clone() const override {
		return new OrQuery(*this);
	}
};

inline Query operator|(const Query &lhs, const Query &rhs) {
	return new OrQuery(lhs, rhs);
}

QueryResult OrQuery::eval(const TextQuery& text) const {
	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}
#endif
