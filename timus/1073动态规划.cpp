#include <iostream>
#include <cmath>

using namespace std;

const int N = 245;
int square[N], res[60001];

int main() {
	for (int i = 0; i < N; ++i) square[i] = i * i;
	res[1] = 1;
	for (int i = 2; i < 60001; ++i) res[i] = 10000;
	for (int i = 2; i < 60001; ++i) {
		int j = floor(sqrt(i + 1));
		while (i < square[j]) --j;
		for (; j > 0; --j) {
			if (i == square[j]) {
				res[i] = 1;
				break;
			}
			else if (res[i - square[j]] + 1 < res[i]) res[i] = res[i - square[j]] + 1;
		}
	}
	int n;
	cin >> n;
	cout << res[n] << endl;
	return 0;
}
