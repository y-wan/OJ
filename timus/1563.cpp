#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> dict;

int main() {
	string s;
	int n, cnt = 0;
	cin >> n;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (!dict.count(s))dict.insert(s);
		else cnt++;
	}
	cout << cnt << endl;
 	return 0;
}
