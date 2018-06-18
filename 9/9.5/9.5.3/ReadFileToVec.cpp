#include <fstream>
#include <string>
#include <vector>

using std::ifstream;
using std::string;
using std::vector;

vector<string> ReadFileToVec(const string &fileName)
{
	ifstream in(fileName);
	vector<string> vec;
	if (in)
	{
		string line;
		while (in >> line)
		{
			vec.push_back(line);
		}
	}
	return vec;
}
