#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n >= 1000)
		cout << "legion\n";
	else if (n >= 500)
		cout << "zounds\n";
	else if (n >= 250)
		cout << "swarm\n";
	else if (n >= 100)
		cout << "throng\n";
	else if (n >= 50)
		cout << "horde\n";
	else if (n >= 20)
		cout << "lots\n";
	else if (n >= 10)
		cout << "pack\n";
	else if (n >= 5)
		cout << "several\n";
	else
		cout << "few\n";
	return 0;
}
