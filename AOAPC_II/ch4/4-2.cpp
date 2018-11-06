#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkSquare(vector<vector<bool>>& h, vector<vector<bool>>& v, int row, int col, int size) {
	for (int i = row; i < row + size; ++i) {
		if (!v[i][col] || !v[i][col + size]) return false;
	}
	for (int j = col; j < col + size; ++j) {
		if (!h[row][j] || !h[row + size][j]) return false;
	}
	// cout << "Found square of size " << size << " at row " << row << ", col " << col << "\n";
	return true;
}

int countSquares(vector<vector<bool>>& h, vector<vector<bool>>& v, int n, int size) {
	int res = 0, m = n - size;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			res += checkSquare(h, v, i, j, size);
		}
	}
	return res;
}

int main() {
	int t = 1, n, m;
	while (cin >> n) {
		cin >> m;
		vector<vector<bool>> h(n + 1, vector<bool>(n + 1, false)), v(n + 1, vector<bool>(n + 1, false));
		if (t > 1) cout << "\n**********************************\n\n";
		cout << "Problem #" << t++ << "\n\n";
		string mark;
		int i, j;
		while (m-- > 0) {
			cin >> mark >> i >> j;
			if (mark == "H") h[i][j] = true;
			else v[j][i] = true;
		}
		bool hasSquare = false;
		for (int i = 1; i < n; ++i) {
			int cnt = countSquares(h, v, n, i);
			if (cnt > 0) {
				hasSquare = true;
				cout << cnt << " square (s) of size " << i << "\n";
			}
		}
		if (!hasSquare) cout << "No completed squares can be found.\n";
	}
	return 0;
}