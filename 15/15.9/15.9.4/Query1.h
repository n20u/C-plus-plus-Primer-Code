#ifndef QUERY_H
#define QUERY_H

#include <string>
#include "WordQuery1.h"
#include "Query_base.h"
#include "..\15.9.3\TextQuery.h"
#include "..\15.9.3\QueryResult.h"

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
	public:
		Query(const std::string&);
		Query(const Query &query): q(query.q->clone()) {}
		QueryResult eval(const TextQuery &t) const {
			return q->eval(t);
		}
		std::string rep() const {
			return q->rep();
		}
		~Query() {
			delete q;
		}
	private:
		Query(Query_base *query) : q(query) {}
		Query_base *q;
};

inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}

#endif
