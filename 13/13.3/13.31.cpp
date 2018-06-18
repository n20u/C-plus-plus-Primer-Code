#include <vector>
#include <algorithm>
#include "HasPtr.h"

using std::vector;

int main()
{
	vector<HasPtr> hpv;
	hpv.push_back(HasPtr("Defence"));
	hpv.push_back(HasPtr("of"));
	hpv.push_back(HasPtr("the"));
	hpv.push_back(HasPtr("Ancients"));
	sort(hpv.begin(), hpv.end());
	return 0;
}
