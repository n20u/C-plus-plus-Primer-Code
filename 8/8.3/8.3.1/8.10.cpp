#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::endl;
using std::ifstream; using std::ofstream;
using std::istringstream;
using std::vector;
using std::string;

int main(int argc, char**argv)
{
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	string line, word;
	vector<string> svec;
	while (getline(in, line))
	{
		svec.push_back(line);
	}
	for (const auto &line : svec)
	{
		istringstream in(line);
		while (in >> word)
		{
			out << word << endl;
		}
	}
	return 0;
}
