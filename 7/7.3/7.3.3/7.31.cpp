#ifndef X
#define X

class Y;

class X
{
	Y *y = nullptr;
};

class Y
{
	X x;
};

#endif
