#include <sstream>
#include "8.1.cpp"

using std::istringstream; using std::ostringstream;

int main()
{
	istringstream iss("hello");
	func(iss);
	return 0;
}
