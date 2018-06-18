#include <string>
#include <vector>
#include <iostream>
#include <utility>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

int main()
{
	cout << "输入string和int的序列：";
	string word;
	int i;
	vector<pair<string, int>> pvec;
	while(cin >> word && cin >> i)
	{
		pair<string, int> p(word, i);
		pvec.push_back(p);
	}
	cout << "输入的序列为：";
	for(const auto &w : pvec)
	{
		cout << w.first << " " << w.second << endl;
	}
	return 0;
}
