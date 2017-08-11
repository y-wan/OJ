//¶¯Ì¬¹æ»®
#include <iostream>

using namespace std;

bool black[501];
int s[501][501], sum_black[501], sum_white[501];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> black[i];
		sum_black[i] = sum_black[i - 1];
		sum_white[i] = sum_white[i - 1];
		if (black[i]) ++sum_black[i];
		else ++sum_white[i];
		s[i][1] = sum_black[i] * sum_white[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= i && j <= k; j++) {
			int min_tmp = s[i - 1][j - 1];
			for (int m = j - 1; m < i; m++) {
				if (s[m][j - 1] + (sum_black[i] - sum_black[m])*(sum_white[i] - sum_white[m]) < min_tmp)
					min_tmp = s[m][j - 1] + (sum_black[i] - sum_black[m])*(sum_white[i] - sum_white[m]);
			}
			s[i][j] = min_tmp;
		}
	}
	cout << s[n][k] << endl;
	return 0;
}