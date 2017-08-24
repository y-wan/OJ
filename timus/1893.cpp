#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void print_res(int row, string s) {
	char c = s[0];
	if (row <= 2)
		if (c == 'A' || c == 'D') cout << "window" << endl;
		else cout << "aisle" << endl;
	else if (row <= 20)
		if (c == 'A' || c == 'F') cout << "window" << endl;
		else cout << "aisle" << endl;
	else
		if (c == 'A' || c == 'K') cout << "window" << endl;
		else if (c == 'C' || c == 'D' || c == 'G' || c == 'H') cout << "aisle" << endl;
		else cout << "neither" << endl;
}

int main() {
	int row;
	string s, col;
	cin >> s;
	stringstream ss(s);
	ss >> row >> col;
	print_res(row, col);	
	return 0;
}
