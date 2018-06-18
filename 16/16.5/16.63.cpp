#include "count.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<double> dvec{ 0.1,1.2,2.3,3.4,4.5,5.6,5.6,5.6 };
	vector<int> ivec{ 0,1,2,3,4,5,5,5 };
	vector<string> svec{ "C","Java","C++","C++","C++" };
	cout << count(5.6, dvec) << endl;
	cout << count(5, ivec) << endl;
	cout << count(static_cast<string>("C++"), svec) << endl;
	system("pause");
	return 0;
}