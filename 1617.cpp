#include <iostream>
#include <map>
using namespace std;

map<int, int> dict;

int main() {
	int d;
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d;
		if (!dict.count(d))dict[d] = 1;
		else dict[d]++;
	}
	for (map<int, int>::iterator it = dict.begin(); it != dict.end(); it++)
		cnt += it->second / 4;
	cout << cnt << endl;
 	return 0;
}
