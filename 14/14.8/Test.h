struct Test {
	int operator()(bool b, int iA, int iB) {
		return b ? iA : iB;
	}
};
