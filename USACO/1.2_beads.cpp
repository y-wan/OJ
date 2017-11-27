/*
ID: wanying1
PROG: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n, ans = 0;
	char c;
	string beads;
    fin >> n >> beads;
	beads += beads + beads;
	for (int i = n; i < 2 * n; ++i) {
		c = 'w';
		int cntLeft = 0, cntRight = 0;
		for (int j = i - 1; j >= 0; --j) {
			if (beads[j] == 'w') ++cntLeft;
			else if (c == 'w') {
				c = beads[j];
				++cntLeft;
			}
			else if (beads[j] == c) ++cntLeft;
			else break;
		}
		c = 'w';
		for (int j = i; j < 3 * n; ++j) {
			if (beads[j] == 'w') ++cntRight;
			else if (c == 'w') {
				c = beads[j];
				++cntRight;
			}
			else if (beads[j] == c) ++cntRight;
			else break;
		}
		ans = max(ans, cntLeft + cntRight);
		ans = min(ans, n);
	}
	fout << ans << endl;
    return 0;
}