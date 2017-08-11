#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> dict[26];

int main() {
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		dict[s[0] - 'a'].insert(s[1] - 'a');
	}
	cin >> s;
	int id = s[0] - 'a';
	for (set<int>::iterator it = dict[id].begin(); it != dict[id].end(); it++)
		cout << s << char('a' + *it) << endl;
 	return 0;
}
