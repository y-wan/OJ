#include <iostream>
using namespace std;

int main() {
	int n, tmp, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp / 2;
	}
	if (sum % 2) cout << "Daenerys" << endl;
	else cout << "Stannis" << endl;
	return 0;
}
