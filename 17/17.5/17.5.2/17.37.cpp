#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main() {
	ifstream input("Text.txt");
	char text[200];
	while (input) {
		input.getline(text, 100);
		cout << text << ' ';
	}
	input.close();
	system("pause");
	return 0;
}