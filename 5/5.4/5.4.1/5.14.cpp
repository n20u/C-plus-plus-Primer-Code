#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::cerr; using std::endl;
using std::string;
using std::vector;

int main()
{
	string word;
	vector<int> ivec;
	vector<int> ivec2;
	vector<string> svec;
	vector<string> svec2;
	unsigned num = 1;
	int max;
	string word2;
	
	if (cin >> word)
	{
	    string word2;
		int i = 1;
			    
	    while(cin >> word2)
	    {
			if (word == word2)
				{
					++i;
				}
			else
				{
					ivec.push_back(i);
					svec.push_back(word);
					
					word = word2;
					i = 1;
				}
		}
		
		ivec.push_back(i);
		svec.push_back(word);
		ivec2.push_back(ivec[0]);
		svec2.push_back(svec[0]);
		
		for (max = ivec[0]; num != ivec.size(); ++num)
		{
			if (ivec[num] >= max)
			{
				ivec2.push_back(ivec[num]);
				svec2.push_back(svec[num]);
				max = ivec[num];
			}
		}
		
		for (int a = 0; a != ivec2.size(); ++a)
		{
			if (ivec2[a] == max)
			{
				cout << "单词" << svec2[a] << "连续出现了" << ivec2[a] << "次" << endl;
			}
		}
		
		return 0;
	}
	else
	{
		cerr << "No data?!";
		return -1;
	}
}
