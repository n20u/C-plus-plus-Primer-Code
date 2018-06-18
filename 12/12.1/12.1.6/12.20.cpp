#include <fstream>
#include <sstream>
#include <iostream>
#include "12.19.h"

using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

int main()
{
	string line;
	ifstream in("StrBlobPtr.txt");
	StrBlob SB;
	while(getline(in, line))
	{
		SB.push_back(line);
	}
	for(StrBlobPtr SBP1(SB.begin()), SBP2(SB.end()); SBP1 != SBP2; SBP1.incr())
	{
		cout << SBP1.deref() << endl;
	}
	return 0;
}
