#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
	int grade;
	
	cout << "请输入成绩：";
	
	cin >> grade;
	
	const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	
	string lettergrade;
	
	if (grade < 60)
	{
		lettergrade = scores[0];
	}
	else
	{
		lettergrade = scores[(grade - 50) / 10];
		
		if (grade != 100)
		{
			if (grade % 10 > 7)
			{
				lettergrade += '+';
			}
			else if (grade % 10 < 3)
			{
				lettergrade += '-';
			}
		}
	}
	
	cout << "成绩为：" << lettergrade << endl;
	
	return 0;
}
