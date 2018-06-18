#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::noskipws;

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, x = 0, y = 0, z = 0;
	char ch;
	
	while (cin >> noskipws >> ch)
	{
		switch (ch)
		{
			case 'a':
			case 'A':
				++aCnt;
				break;
			case 'e':
			case 'E':
				++eCnt;
				break;
			case 'i':
			case 'I':
				++iCnt;
				break;
			case 'o':
			case 'O':
				++oCnt;
				break;
			case 'u':
			case 'U':
			    ++uCnt;
				break;
			case ' ':
				++x;
				break;
			case '\t':
				++y;
				break;
			case '\n':
				++z;
				break;
		}
	}
	
	cout << "Number of vowel a: \t" << aCnt << '\n'
	     << "Number of vowel e: \t" << eCnt << '\n'
	     << "Number of vowel i: \t" << iCnt << '\n'
	     << "Number of vowel o: \t" << oCnt << '\n'
	     << "Number of vowel u: \t" << uCnt << '\n'
	     << "Number of vowel space: \t" << x << '\n'
	     << "Number of vowel tab: \t" << y << '\n'
	     << "Number of vowel enter: \t" << z << endl;
	
	return 0;
}
