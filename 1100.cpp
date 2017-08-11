#include <iostream>
#include <queue>
using namespace std;

queue<int> team[101];

int main() {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		team[b].push(a);
	}
	for (int i = 100; i >= 0; i--) {
		while (!team[i].empty()) {
			cout << team[i].front() << ' ' << i << endl;
			team[i].pop();
		}
	}
	return 0;
}
