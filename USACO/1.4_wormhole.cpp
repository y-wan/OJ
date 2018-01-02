/*
ID: wanying1
PROG: wormhole
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <set>  // storing pairings of the wormholes
#include <vector>
#define MAX 1000000001
using namespace std;

typedef vector<pair<int, int> > WH;
typedef vector<int> paired_WH;

bool is_stuck(const WH &wormholes, paired_WH paired_wormholes) {
	int n = wormholes.size();
	for (int i = 0; i < n; ++i) {
		vector<bool> visited(n), visited_out(n);
		visited[i] = true;
		int x = wormholes[paired_wormholes[i]].first, y = wormholes[paired_wormholes[i]].second;
		while (true) {
			int next_x = MAX, next_id = -1;
			for (int i = 0; i < n; ++i) {
				if (wormholes[i].second == y && wormholes[i].first > x && wormholes[i].first < next_x) {
					next_x = wormholes[i].first;
					next_id = i;
				}
			}
			if (next_id != -1) {
				if (visited[next_id])
					return true;
				visited[next_id] = true;
				x = wormholes[paired_wormholes[next_id]].first, y = wormholes[paired_wormholes[next_id]].second;
			}
			else break;
		}
	}
	return false;
}

void enumerate_wormholes(const WH &wormholes, paired_WH &paired_wormholes, vector<bool> &is_paired, int left, int &cnt) {
	int w1 = 0, n = wormholes.size();
	while (is_paired[w1]) ++w1;
	is_paired[w1] = true;
	for (int w2 = 0; w2 < n; ++w2) {
		if (!is_paired[w2]) {
			is_paired[w2] = true;
			paired_wormholes[w1] = w2;
			paired_wormholes[w2] = w1;
			if (left <= 2) {
				if (is_stuck(wormholes, paired_wormholes)) ++cnt;
			}
			else enumerate_wormholes(wormholes, paired_wormholes, is_paired, left - 2, cnt);
			is_paired[w2] = false;
			paired_wormholes[w1] = -1;
			paired_wormholes[w2] = -1;
		}
	}
	is_paired[w1] = false;
}

int main() {
	ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");
	int n, cnt = 0;
	fin >> n;
	WH wormholes(n);
	paired_WH paired_wormholes(n, -1);
	vector<bool> is_paired(n, false);
	for (int i = 0; i < n; ++i) {
		fin >> wormholes[i].first >> wormholes[i].second;
	}
	enumerate_wormholes(wormholes, paired_wormholes, is_paired, n, cnt);
	fout << cnt << endl;
	return 0;
}
