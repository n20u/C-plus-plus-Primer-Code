#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include <string>
#include "..\15.9.3\QueryResult.h"
#include "..\15.9.3\TextQuery.h"

class Query_base {
	friend class Query;
	protected:
		using line_no  = TextQuery::line_no;
		virtual ~Query_base() = default;
	private:
		virtual QueryResult eval(const TextQuery&) const = 0;
		virtual std::string rep() const = 0;
		virtual Query_base* clone() const = 0;
};

#endif
