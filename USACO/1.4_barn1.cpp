/*
ID: wanying1
PROG: barn1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int m, s, c, start, prev, cur, ans;
    fin >> m >> s >> c;
	vector<int> v, tmp(c);
	for (int i = 0; i < c; ++i) fin >> tmp[i];
	sort(tmp.begin(), tmp.end());
	for (int i = 1; i < c; ++i)
		if (tmp[i] - tmp[i - 1] > 1) v.push_back(tmp[i] - tmp[i - 1] - 1);
	ans = tmp[c - 1] - tmp[0] + 1;
	sort(v.begin(), v.end());
	reverse(v.begin(),v.end());
	vector<int>::iterator it = v.begin();
	for (int i = 1; i < m && it != v.end(); ++i, ++it) {
		ans -= *it;
	}
	fout << ans << endl;
    return 0;
}