#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, tmp, sum = 0;
	bool not_ex = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 3) {
			cout << "None" << endl;
			return 0;
		}
		else if (tmp == 4) {
			sum += 4;
			not_ex = true;
		}
		else sum += 5;
	}
	if (!not_ex) cout << "Named" << endl;
	else if (sum >= 4.5*n - 1e-6) cout << "High" << endl;
	else cout << "Common" << endl;
	return 0;
}
