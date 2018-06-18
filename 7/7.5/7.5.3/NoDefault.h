#ifndef NODEFAULT
#define NODEFAULT

struct NoDefault
{
	NoDefault(int i) { }
};

struct C
{
	C() : def(0) { }
	
	private:
		NoDefault def;
};

#endif
