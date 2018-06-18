#pragma once
class Class { /*...*/ };

class Base :public Class {
public:
	Base() :ival(0),Class() {}
	Base(const Base &b) = default;
	Base(int ival) :ival(ival),Class() {}
private:
	int ival;
};

class D1 :virtual public Base {
public:
	D1() :Base() {}
	D1(const D1 &d1) = default;
	D1(int ival) :Base(ival) {}
};

class D2 :virtual public Base {
public:
	D2() :Base() {}
	D2(const D2 &d2) = default;
	D2(int ival) :Base(ival) {}
};

class MI :public D1, public D2 {
public:
	MI() : Base(), D1(), D2() {}
	MI(const MI &m) : Base(m), D1(m), D2(m) {}
	MI(int ival) : Base(ival), D1(ival), D2(ival) {}
};

class Final : public MI, public Class {
public:
	Final() : Base(), MI(), Class() {}
	Final(const Final &f) : Base(f), MI(f), Class() {}
	Final(int ival) : Base(ival), MI(ival), Class() {}
};