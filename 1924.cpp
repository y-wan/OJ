#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	if (a % 4 == 1 || a % 4 == 2)
		cout << "grimy" << endl;
	else
		cout << "black" << endl;
	return 0;
}
