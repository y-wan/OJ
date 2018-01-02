/*
ID: wanying1
PROG: skidesign
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int cost(const vector<int> &v, vector<int> v_final, bool change_hi = true) {
	int n = v_final.size(), c = 0;
	if (change_hi) {
		int a = v_final[n - 1];
		for (int i = n - 1; i >= 0; --i) {
			if (v_final[i] < a) break;
			--v_final[i];
		}
	}
	else {
		int a = v_final[0];
		for (int i = 0; i < n; ++i) {
			if (v_final[i] > a) break;
			++v_final[i];
		}
	}
	for (int i = 0; i < n; ++i)
		c += (v_final[i] - v[i])*(v_final[i] - v[i]);
	return c;
}

int main() {
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
	int n, ans = 0;
	fin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) fin >> v[i];
	sort(v.begin(), v.end());
	vector<int> v_final(v);
	while (v_final[n - 1] - v_final[0] > 17) {
		if (cost(v, v_final, true) < cost(v, v_final, false)) {
			int a = v_final[n - 1];
			for (int i = n - 1; i >= 0; --i) {
				if (v_final[i] < a) break;
				--v_final[i];
			}
		}
		else {
			int a = v_final[0];
			for (int i = 0; i < n; ++i) {
				if (v_final[i] > a) break;
				++v_final[i];
			}
		}
	}
	for (int i = 0; i < n; ++i)
		ans += (v_final[i] - v[i])*(v_final[i] - v[i]);
	fout << ans << endl;
	return 0;
}
