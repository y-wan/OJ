#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int>dict;

int main() {
	int n, cnt, max = 0;
	string s, maxs = "";
	dict["Emperor Penguin"] = 0;
	dict["Macaroni Penguin"] = 0;
	dict["Little Penguin"] = 0;
	cin >> n;
	getline(cin, s);
	for (int i = 1; i <= n; i++) {
		getline(cin, s);
		dict[s]++;
	}
	for (map<string, int>::iterator it = dict.begin(); it != dict.end(); it++) {
		if (it->second > max) {
			max = it->second;
			maxs = it->first;
		}
	}
	cout << maxs << endl;
	return 0;
}
