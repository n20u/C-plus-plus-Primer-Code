#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::noskipws;

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, x = 0, y = 0, z = 0, sum_ff = 0, sum_fl = 0, sum_fi = 0;
	char ch, char_before;
	
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
				if (char_before == 'f')
				{
					++sum_fi;
				}
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
			case 'f':
				if (char_before == 'f')
				{
					++sum_ff;
				}
				break;
			case 'l':
				if (char_before == 'f')
				{
					++sum_fl;
				}
				break;
		}
		
		char_before = ch;
	}
	
	cout << "Number of vowel a: \t" << aCnt << '\n'
	     << "Number of vowel e: \t" << eCnt << '\n'
	     << "Number of vowel i: \t" << iCnt << '\n'
	     << "Number of vowel o: \t" << oCnt << '\n'
	     << "Number of vowel u: \t" << uCnt << '\n'
	     << "Number of vowel space: \t" << x << '\n'
	     << "Number of vowel tab: \t" << y << '\n'
	     << "Number of vowel enter: \t" << z << '\n'
	     << "Number of vowel ff: \t" << sum_ff << '\n'
	     << "Number of vowel fl: \t" << sum_fl << '\n'
	     << "Number of vowel fi: \t" << sum_fi << endl;
	
	return 0;
}
