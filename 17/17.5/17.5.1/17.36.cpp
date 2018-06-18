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
	cout << setw(16) << right << "default format: " << 100 * sqrt(2.0) << '\n'
		<< setw(16) << right << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		<< setw(16) << right << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		<< setw(16) << right << "hexadecimal: " << hexfloat << uppercase << 100 * sqrt(2.0) << nouppercase << '\n'
		<< setw(16) << right << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << "\n";
	system("pause");
	return 0;
}