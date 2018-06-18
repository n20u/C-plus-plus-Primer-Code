#ifndef DATE
#define DATE
#include <string>
#include <vector>

using std::string;
using std::vector;

class date
{
	public:
		date(string);
		unsigned getyear()
		{
			return y;
		}
		unsigned getmonth()
		{
			return m;
		}
		unsigned getday()
		{
			return d;
		}
	private:
		unsigned y;
		unsigned m;
		unsigned d;
};

date::date(string s)
{
	string year;
	string month;
	string day;
	int i = 0;
	for (string::size_type pos = 0; pos < s.size(); ++pos)
	{
		if (isalnum(s[pos]))
		{
			switch (i)
			{
				case 0:
					month.push_back(s[pos]);
					break;
				case 1:
					day.push_back(s[pos]);
					break;
				case 2:
					year.push_back(s[pos]);
					break;
				default:
					break;
			}
		}
		if (!isalnum(s[pos]) && isalnum(s[pos - 1]))
		{
			++i;
		}
	}
	y = stoi(year);
	if (isalpha(month[0]))
	{
		vector<string> msev{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		for (vector<string>::size_type pos = 0; pos < msev.size(); ++pos)
		{
			if (!msev[pos].compare(0, month.size(), month))
			{
				m = pos + 1;
			}
		}
	}
	else
	{
		m = stoi(month);
	}
	d = stoi(day);
}

#endif
