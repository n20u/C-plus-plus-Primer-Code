#include <iostream>
#include <vector>

using std::vector;
using std::cin; using std::cout; using std::endl;

int main()
{
	unsigned grade;
	vector<unsigned> scores(11, 0);
	auto i = scores.begin();
	
	cout << "请输入一组成绩：";
	
	while(cin >> grade)
	    ++*(i + grade/10);
    cout << endl;
    
	for (auto i = scores.cbegin(); i != scores.cend(); ++i)
        cout << *i << " ";
	cout << endl;
	
	return 0;
}
