#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout; using std::cin; using std::endl;

int main()
{
	vector<int> v1;
	for (auto i = v1.cbegin(); i != v1.cend() && !isspace(*i); ++i)
	    cout << *i << ",";
	cout << endl;
	
	vector<int> v2(10);
	for (auto i = v2.cbegin(); i != v2.cend() && !isspace(*i); ++i)
	    cout << *i << ",";
	cout << endl;
	
	vector<int> v3(10,42);
	for (auto i = v3.cbegin(); i != v3.cend() && !isspace(*i); ++i)
	    cout << *i << ",";
	cout << endl;
	
	vector<int> v4{10};
	for (auto i = v4.cbegin(); i != v4.cend() && !isspace(*i); ++i)
	    cout << *i << ",";
	cout << endl;
	
	vector<int> v5{10,42};
	for (auto i = v5.cbegin(); i != v5.cend() && !isspace(*i); ++i)
	    cout << *i << ",";
	cout << endl;
	
	vector<string> v6{10};
	for (auto i = v6.cbegin(); i != v6.cend() && !i->empty(); ++i)
	    cout << *i << ",";
	cout << endl;
	
	vector<string> v7{10, "hi"};
	for (auto i = v7.cbegin(); i != v7.cend() && !i->empty(); ++i)
	    cout << *i << ",";
	
	return 0;
}
