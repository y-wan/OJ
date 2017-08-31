#include <iostream>
#include <queue>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m, tmp, mine, ans = 0;
		cin >> n >> m;
		queue<pair<int, int> > q;
		priority_queue<pair<int, int> > pq;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			q.push(make_pair(tmp, j));
			pq.push(make_pair(tmp, j));
			if (j == m)
				mine = tmp;
		}
		while (true) {
			pair<int, int> pair_tmp;
			pair_tmp = q.front();
			if (pair_tmp.first == pq.top().first) {
				q.pop();
				pq.pop();
				ans++;
				if (pair_tmp.second == m)
					break;
			}
			else {
				q.pop();
				q.push(pair_tmp);
			}
		}
		cout << ans << endl;
	}
	return 0;
}