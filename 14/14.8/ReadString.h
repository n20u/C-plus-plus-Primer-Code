#include <iostream>
#include <string>

class ReadString {
	public:
		ReadString(std::istream &i = std::cin) : is(i) {}
		std::string operator()() const {
			std::string s;
			std::getline(is, s);
			return is ? s : std::string();
		}
	private:
		std::istream &is;
};
