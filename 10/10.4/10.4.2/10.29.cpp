#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::istream_iterator;

int main()
{
	ifstream in("stringFile.txt");
	istream_iterator<string> in_iter(in), eof;
	vector<string> svec;
	while (in_iter != eof)
	{
		svec.push_back(*in_iter++);
	}
	for_each(svec.cbegin(), svec.cend(), [](const string &s){cout << s << " ";});
	return 0;
}
