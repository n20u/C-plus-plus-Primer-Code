#include <iostream>
#include <vector>
#include "Fpvec.h"

using std::vector;

int fun1(int a, int b)
{
	return a + b;
}

int fun2(int a, int b)
{
	return a - b;
}

int fun3(int a, int b)
{
	return a * b;
}

int fun4(int a, int b)
{
	return a / b;
}

void func()
{
	Fpvec.push_back(fun1);
	Fpvec.push_back(fun2);
	Fpvec.push_back(fun3);
	Fpvec.push_back(fun4);
}
