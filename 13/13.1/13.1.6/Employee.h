#include <string>

using std::string;

class Employee
{
	public:
		Employee() : name(), number(++i) {}
		Employee(const string &name) : name(name), number(++i) {}
		Employee(const Employee&) = delete;
		Employee& operator=(const Employee&) = delete;
		~Employee();
		const int id()
		{
			return number;
		}
	private:
		string name;
		int number;
		static int i;
};

int Employee::i = 0;
