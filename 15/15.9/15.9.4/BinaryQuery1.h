#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include <string>
#include "Query1.h"
#include "Query_base.h"
#include "..\15.9.3\TextQuery.h"
#include "..\15.9.3\QueryResult.h"

class BinaryQuery: public Query_base {
	protected:
		BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) {}
		std::string rep() const {
			return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
		}
		Query lhs, rhs;
		std::string opSym;
};

#endif
