#include <iostream>
#include <fstream>
#include "Query.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "..\15.9.3\TextQuery.h"
#include "..\15.9.3\QueryResult.h"

using std::cout;
using std::ifstream;

int main() {
	Query q = Query("is") & Query("a") | Query("Java");
	ifstream infile("Text.txt");
	TextQuery tp(infile);
	print(cout, q.eval(tp));
	return 0;
}
