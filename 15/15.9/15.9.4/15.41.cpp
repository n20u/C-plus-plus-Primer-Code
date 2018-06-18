#include <iostream>
#include <fstream>
#include "Query1.h"
#include "AndQuery1.h"
#include "OrQuery1.h"
#include "..\15.9.3\TextQuery.h"
#include "..\15.9.3\QueryResult.h"

using std::cout;
using std::endl;
using std::ifstream;

int main() {
	Query q = Query("is") & Query("a") | Query("C");
	ifstream infile("Text.txt");
	TextQuery tp(infile);
	print(cout, q.eval(tp));
	system("pause");
	return 0;
}
