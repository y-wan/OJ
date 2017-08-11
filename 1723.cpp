#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> dict;

int main() {
	string s;
	cin >> s;
	int n = s.size(), max = 0;
	char maxc;
	for (int i = 0; i < n; i++) {
		if (!dict.count(s[i]))dict[s[i]] = 1;
		else dict[s[i]]++;
	}
	for (map<char, int>::iterator it = dict.begin(); it != dict.end(); it++)
		if (it->second >= max) {
			maxc = it->first;
			max = it->second;
		}
	cout << maxc << endl;
 	return 0;
}
