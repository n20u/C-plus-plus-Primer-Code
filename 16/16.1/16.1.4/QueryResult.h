#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <set>
#include "TextQuery.h"

class TextQuery;
class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
	public:
		QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) { }
		std::set<TextQuery::line_no>::iterator begin() const
		{
			return lines->begin();
		}
		std::set<TextQuery::line_no>::iterator end() const
		{
			return lines->end();
		}
		std::shared_ptr<std::vector<std::string>> get_file() const
		{
			return file;
		}
	private:
		std::string sought;
		std::shared_ptr<std::set<TextQuery::line_no>> lines;
		std::shared_ptr<std::vector<std::string>> file; 
};

QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
	{
		return QueryResult(sought, nodata, file);
	}
	else
	{
		return QueryResult(sought, loc->second, file);
	}
}

std::string make_plural(std::size_t curr, const std::string &word, const std::string &ending)
{
	return (curr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	for(auto num : *qr.lines)
	{
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	}
	return os;
}
