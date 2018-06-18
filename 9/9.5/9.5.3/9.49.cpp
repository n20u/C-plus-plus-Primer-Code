#include <fstream>
#include <vector>
#include <string>
#include "ReadFileToVec.cpp"

using std::ofstream;
using std::vector;
using std::string;

int main(int argc, char **argv)
{
	vector<string> svec1 = ReadFileToVec(argv[1]);
	vector<string> svec2;
	string str1("bdfhklt");
	string str2("gjpqy");
	for (const auto &str : svec1)
	{
		string::size_type pos = 0;
		if (((pos = str.find_first_of(str1, 0)) == string::npos) && ((pos = str.find_first_of(str2, 0)) == string::npos))
		{
			svec2.push_back(str);
		}
	}
	string::size_type max = 0;
	string smax;
	for (const auto &str : svec2)
	{
		if (str.size() > max)
		{
			max = str.size();
			smax = str;
		}
	}
	ofstream out(argv[2]);
	out << smax;
	return 0;
}
