#include <iostream>
#include <string>
using namespace std;

int a[105][105], t[105];

int max_sum(int *t, int n) {
	int max_s = -127, res = 0;
	for (int i = 0; i < n; i++) {
		//max_val = max_val > t[i] ? max_val : t[i];
		res += t[i];
		max_s = max_s > res ? max_s : res;
		res = res > 0 ? res : 0;
	}
	return max_s;
}

int main() {	
	int n, res = -10000;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++) t[i] = a[0][i];
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < n; x++) t[x] = 0;
		for (int j = i; j < n; j++) {
			for (int x = 0; x < n; x++) t[x] += a[j][x];
			int tmp = max_sum(t, n);
			res = res > tmp ? res : tmp;
		}
	}
	cout << res << endl;
	return 0;
}
