#include <iostream>
using namespace std;

int main() {
	int n, old, tmp, cnt = 0;
	bool first = true;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (i != 0 && tmp == old) cnt++;
		else {
			if (i > 0) {
				if (first) first = false;
				else cout << ' ';
				cout << cnt << ' ' << old;
			}
			cnt = 1;
			old = tmp;
		}
	}
	if (first) first = false;
	else cout << ' ';
	cout << cnt << ' ' << old << endl;
	return 0;
}
