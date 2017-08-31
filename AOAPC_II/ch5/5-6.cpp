#include <iostream>
#include <map>
#include <cstring>
//#include <ctime>
using namespace std;

bool equal(double a, double b) {
	return a - b < 1e-6 && b - a < 1e-6;
}

int dots[20001];

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(dots, 0, sizeof(dots));
		int n, x, y;
		map<int, int> cnt;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			dots[y + 10000] += x;
			if (!cnt.count(y + 10000))
				cnt[y + 10000] = 1;
			else
				cnt[y + 10000]++;
		}
		map<int, int>::iterator it = cnt.begin();
		double axis = (double)dots[it->first] / it->second;
		bool yes = true;
		for (++it; it != cnt.end(); it++) {
			//cout << it->first << " " << it->second << " " << (double)dots[it->first] / it->second << " " << axis << endl;
			if (!equal((double)dots[it->first] / it->second, axis)) {
				cout << "NO" << endl;
				yes = false;
				break;
			}
		}
		if (yes)
			cout << "YES" << endl;
	}
	return 0;
}