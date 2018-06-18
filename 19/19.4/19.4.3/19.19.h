#pragma once
#include <vector>
#include <algorithm>
#include "../../../18/18.1/18.1.5/Sales_data.h"

std::vector<Sales_data>::iterator overAvg(std::vector<Sales_data> svec, double d) {
	return std::find_if(svec.begin(), svec.end(), [d](const Sales_data &s) { return d < s.avg_price();  });
}