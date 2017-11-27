/*
ID: wanying1
PROG: milk
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int n, m, ans = 0;
    fin >> n >> m;
	vector<pair<int, int> > v(m);
	for (int i = 0; i < m; ++i)
		fin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	for (int i = 0; i < m; ++i) {
		if (n > v[i].second) {
			n -= v[i].second;
			ans += v[i].first * v[i].second;
		}
		else {
			ans += v[i].first * n;
			break;
		}
	}
	fout << ans << endl;
    return 0;
}