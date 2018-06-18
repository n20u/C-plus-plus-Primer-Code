#pragma once
#include <cstdlib>
#include <new>

using std::malloc;
using std::free;
using std::bad_alloc;

void *operator new(size_t size) {
	if (void *mem = malloc(size))
	{
		return mem;
	}
	else
	{
		throw bad_alloc();
	}
}

void operator delete(void *mem) noexcept {
	free(mem);
}