#include <iostream>
using namespace std;

int main() {
	int n, tmp, sum = 0, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		max = max > tmp ? max : tmp;
	}
	sum += max;
	cout << sum << endl;
	return 0;
}
