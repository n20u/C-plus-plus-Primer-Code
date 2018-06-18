#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin; using std::cout; using std::endl;

int main()
{
	string word;
	vector<string> text;
	
	cout << "ÇëÊäÈëÒ»×é´Ê£º";
	
	while(cin >> word)
	    text.push_back(word);
	
	for (auto i : text)
	{
		for (auto &j : i)
		    j = toupper(j);
		cout << i << endl;
	}
	
	return 0;
}
