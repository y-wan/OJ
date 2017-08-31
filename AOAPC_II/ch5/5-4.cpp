#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	string s1, s2;
	while (cin >> n && n) {
		map<string, int> from;
		map<string, int> to;
		bool yes = true;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			if (!from.count(s1))
				from[s1] = 1;
			else
				from[s1]++;
			if (!to.count(s2))
				to[s2] = 1;
			else
				to[s2]++;
		}
		map<string, int>::iterator it;
		for (it = from.begin(); it != from.end(); it++)
			if (!to.count(it->first) || to[it->first] != it->second)
				yes = false;
		for (it = to.begin(); it != to.end(); it++)
			if (!from.count(it->first))
				yes = false;
		if (yes)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}