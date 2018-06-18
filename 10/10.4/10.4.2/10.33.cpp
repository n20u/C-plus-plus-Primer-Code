#include <iterator>
#include <fstream>

using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::ofstream;

int main(int argc, char** argv)
{
	ifstream in(argv[1]);
	ofstream out1(argv[2]);
	ofstream out2(argv[3]);
	istream_iterator<int> input(in), eof;
	ostream_iterator<int> output1(out1, " "), output2(out2, "\n");
	while(input != eof)
	{
		if(*input % 2)
		{
			output1 = *input++;
		}
		else
		{
			output2 = *input++;
		}
	}
	return 0;
}
