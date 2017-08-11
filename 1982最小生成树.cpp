//最小生成树（Kruskal）+bfs
#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int> > > pq;
int path[101][101], powered_count = 0; // bfs_visited_count
bool powered[101], connect[101][101]; // bfs_visited[101]

void bfs_power_up(const int center, const int n) {
	for (int i = 1; i <= n; i++) {
		if (powered_count == n) return;
		if (connect[center][i] && !powered[i]) {
			powered[i] = true;
			++powered_count;
			//++bfs_visited_count;
			bfs_power_up(i, n);
		}
	}
}

int main() {
	int n, k, t;
	long long cost = 0;
	cin >> n >> k;
	while (k-- > 0) {
		cin >> t;
		powered[t] = true;
		++powered_count;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> path[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			pq.push(make_pair(-path[i][j], make_pair(i, j)));
	while (!pq.empty() && powered_count < n) {
		pair<int, pair<int, int> > tmp = pq.top();
		pq.pop();
		while (powered[tmp.second.first] && powered[tmp.second.second]) {
			tmp = pq.top();
			pq.pop();
		}
		int i = tmp.second.first, j = tmp.second.second;
		cost -= tmp.first;
		connect[i][j] = connect[j][i] = true;
		if (!powered[i] && powered[j]) {
			powered[i] = true;
			++powered_count;
			bfs_power_up(i, n);
		}
		else if (powered[i] && !powered[j]) {
			powered[j] = true;
			++powered_count;
			bfs_power_up(j, n);
		}
	}
	cout << cost << endl;
	return 0;
}