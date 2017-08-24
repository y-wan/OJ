#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	//ios_base::sync_with_stdio(false);
	int n;
	double a[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	if (n == 1) {
		cout << a[0] << endl;
		return 0;
	}
	double res = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		res = 2 * sqrt(res * a[i]);
	}
	printf("%.2f\n", res);
	return 0;
}
