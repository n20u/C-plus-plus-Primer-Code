#include <iostream>
#include <fstream>
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream &infile)
{
	TextQuery tp(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		if (!(cin >> s) || s == "q")
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
	system("pause");
	return 0;
}