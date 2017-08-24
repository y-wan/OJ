#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a % 2 == 0 || b % 2 == 0)
		cout << "[:=[first]" << endl;
	else
		cout << "[second]=:]" << endl;
	return 0;
}
