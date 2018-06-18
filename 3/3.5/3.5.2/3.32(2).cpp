#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector;

int main()
{
	vector<int> v;
	
	for (int i = 0; i < 10; ++i)
	    v.push_back(i);
	    
	vector<int> v1(v);
	    
	for (auto i : v1)
	    cout << i << " ";
	cout << endl;
	
	return 0;
}
