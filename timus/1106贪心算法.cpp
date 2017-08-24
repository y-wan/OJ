//Ì°ĞÄËã·¨
#include <iostream>
#include <set>
using namespace std;

set<int> link[105], all_mem, res;
bool done[105];

void print_set(int n) {
	for (int i = 0; i < n; i++) {
		cout << "i=" << i + 1 << ": ";
		for (set<int>::iterator it = link[i].begin(); it != link[i].end(); it++) {
			cout << *it + 1 << ' ';
		}
		cout << endl;
	}
}

bool all_done(int n) {
	for (int i = 0; i < n; i++)
		if (!done[i])
			return false;
	return true;
}

int max_set(int n) {
	int max_size = 0, max_id = -1, tmp;
	for (int i = 0; i < n; i++) {
		if (done[i]) continue;
		tmp = link[i].size();
		if (tmp > max_size) {
			max_size = tmp;
			max_id = i;
		}
	}
	return max_id;
}

int main() {
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		while (cin >> tmp && tmp != 0)
			link[i].insert(tmp - 1);
	}

	//print_set(n);

	while (!all_done(n)) {
		int to_move = max_set(n);
		done[to_move] = true;
		res.insert(to_move);
		set<int> &tmp_set = link[to_move];
		set<int>::iterator it;
		for (it = tmp_set.begin(); it != tmp_set.end(); it++)
			done[*it] = true;
	}
	cout << res.size() << endl;
	for (set<int>::iterator it = res.begin(); it != res.end(); it++) {
		if (it != res.begin()) cout << ' ';
		cout << *it + 1;
	}
	cout << endl;
	return 0;
}