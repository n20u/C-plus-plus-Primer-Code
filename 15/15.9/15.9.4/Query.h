#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <memory>
#include "WordQuery.h"
#include "..\15.9.3\Query_base.h"
#include "..\15.9.3\TextQuery.h"
#include "..\15.9.3\QueryResult.h"

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
	public:
		Query(const std::string&);
		QueryResult eval(const TextQuery &t) const {
			return q->eval(t);
		}
		std::string rep() const {
			return q->rep();
		}
	private:
		Query(std::shared_ptr<Query_base> query) : q(query) {}
		std::shared_ptr<Query_base> q;
};

inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}

#endif
