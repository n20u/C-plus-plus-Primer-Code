#pragma once
#include <iostream>
#include "../../16.3/debug_rep.h"
#include "../16.4.1/print.h"

template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest) {
	return print(os, debug_rep(rest)...);
}