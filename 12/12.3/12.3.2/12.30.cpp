#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <set>

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::shared_ptr;
using std::map;
using std::set;

string make_plural(size_t curr, const string &word, const string &ending)
{
	return (curr > 1) ? word + ending : word;
}

class QueryResult;
class TextQuery
{
	public:
		using line_no = vector<string>::size_type;
		TextQuery(ifstream&);
		QueryResult query(const string&) const;
	private:
		shared_ptr<vector<string>> file;
		map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line >> word)
		{
			auto &lines = wm[word];
			if(!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
	public:
		QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) { }
	private:
		string sought;
		shared_ptr<set<TextQuery::line_no>> lines;
		shared_ptr<vector<string>> file; 
};

QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
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

ostream &print(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	<< make_plural(qr.lines->size(), "time", "s") << endl;
	for(auto num : *qr.lines)
	{
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	}
	return os;
}

void runQueries(ifstream &infile)
{
	TextQuery tp(infile);
	while(true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		if(!(cin >> s) || s == "q")
		{
			break;
		}
		print(cout, tp.query(s)) << endl;
	}
}

int main()
{
	ifstream infile("Text.txt");
	runQueries(infile);
	return 0;
}
