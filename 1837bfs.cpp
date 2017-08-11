//bfs
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

map<string, int> name_id;
set<int> mate[305];
int state[305];


void bfs(queue<int> q, int depth) {
	queue<int>q1;
	while (!q.empty()) {

		int i = q.front();
		q.pop();
		for (set<int>::iterator it = mate[i].begin(); it != mate[i].end(); it++) {
			if (state[*it] == -1) {
				state[*it] = depth;
				q1.push(*it);
			}
		}
	}
	if (!q1.empty()) bfs(q1, depth + 1);
}

int main() {
	int n, id = 0;
	string s[3];
	memset(state, -1, sizeof(state));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> s[j];
			if (!name_id.count(s[j])) name_id[s[j]] = id++;
		}
		for (int j = 0; j < 3; j++) {
			mate[name_id[s[j]]].insert(name_id[s[(j + 1) % 3]]);
			mate[name_id[s[(j + 1) % 3]]].insert(name_id[s[j]]);
		}
	} // final id == # of people
	if (!name_id.count("Isenbaev")) {
		for (map<string, int>::iterator it = name_id.begin(); it != name_id.end(); it++)
			cout << it->first << " undefined" << endl;
		return 0;
	}
	int center = name_id["Isenbaev"];
	state[center] = 0;
	queue<int> q;
	q.push(center);
	bfs(q, 1);
	for (map<string, int>::iterator it = name_id.begin(); it != name_id.end(); it++) {
		if (state[it->second] == -1)
			cout << it->first << " undefined" << endl;
		else
			cout << it->first << " " << state[it->second] << endl;
	}
	return 0;
}