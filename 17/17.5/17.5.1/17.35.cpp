#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::uppercase;
using std::nouppercase;
using std::setw;
using std::right;
using std::left;
using std::sqrt;

int main() {
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		<< "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		<< "hexadecimal: " << hexfloat << uppercase << 100 * sqrt(2.0) << nouppercase << '\n'
		<< "use defaults: " << defaultfloat << 100 * sqrt(2.0) << "\n";
	system("pause");
	return 0;
}