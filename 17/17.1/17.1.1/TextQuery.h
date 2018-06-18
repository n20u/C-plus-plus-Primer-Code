#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include <tuple>
#include <algorithm>
#include "DebugDelete.h"

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	using stuple = 
		std::tuple<std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>>;
	TextQuery(std::ifstream&);
	stuple query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>, DebugDelete())
{
	std::string text;
	while (std::getline(is, text))
	{
		file->push_back(text);
		auto n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
			{
				lines.reset(new std::set<line_no>);
			}
			lines->insert(n);
		}
	}
}

TextQuery::stuple TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
	{
		return std::make_tuple(sought, nodata, file);
	}
	else
	{
		return std::make_tuple(sought, loc->second, file);
	}
}

std::string make_plural(std::size_t curr, const std::string &word, const std::string &ending)
{
	return (curr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, const TextQuery::stuple &qr)
{
	os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " "
		<< make_plural(std::get<1>(qr)->size(), "time", "s") << std::endl;
	for (auto num : *std::get<1>(qr))
	{
		os << "\t(line " << num + 1 << ") " << *(std::get<2>(qr)->begin() + num) << std::endl;
	}
	return os;
}