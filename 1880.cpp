#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, int> dict;

int main() {
	int a, tmp, kase = 0, res = 0;
	while (cin >> a) {
		kase++;
		for (int i = 0; i < a; i++) {
			cin >> tmp;
			if (!dict.count(tmp)) dict[tmp] = 1;
			else dict[tmp]++;
		}
	}
	for (map<int, int>::iterator it = dict.begin(); it != dict.end(); it++)
		if (it->second == kase) res++;
	cout << res << endl;
	return 0;
}
