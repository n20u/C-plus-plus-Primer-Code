#include <map>
#include <string>
#include <iostream>

using std::multimap;
using std::string;
using std::cout;
using std::endl;

int main()
{
	multimap<string, string> authors{{"a", "A"}, {"a", "B"}, {"b", "C"}, {"b", "D"}, {"c", "E"}, {"c", "F"}};
	string author{"a"}, work{"B"};
	for(auto found = authors.find(author); found != authors.end() && found->first == author; )
	{
		if(found->second == work)
		{
			found = authors.erase(found);
		}
		else
        {
        	++found;
		}
    }
	for (const auto& author : authors)
	{
		cout << author.first << " " << author.second << endl;
	}
	return 0;
} 
