#include <iostream>

using namespace std;

bool a2b[1001][1001];
int arr[1001];

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a2b[a][b] = true;
	}
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a2b[arr[j]][arr[i]]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}
