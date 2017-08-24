#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> dict, spammer;

int main() {
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (dict.count(s)) spammer.insert(s);
		else dict.insert(s);
	}
	for (set<string>::iterator it = spammer.begin(); it != spammer.end(); it++)
		cout << *it << endl;
 	return 0;
}
