#include <iostream>
#include <string>
using namespace std;

int main() {	
	string s;
	cin >> s;
	int n = s.size(), center = -1, max_len = -1;
	bool even = false;
	for (int i = 0; i < n; i++) {
		int len = 0;
		while (i - len >= 0 && i + len < n && s[i - len] == s[i + len]) len++;
		if ((--len)*2+1 > max_len) {
			center = i;
			max_len = len * 2 + 1;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) continue;
		int len = 0;
		while (i - len >= 0 && i + 1 + len < n && s[i - len] == s[i + 1 + len]) len++;
		if ((--len)*2+2 > max_len) {
			center = i;
			even = true;
			max_len = len * 2 + 2;
		}
	}
	if (!even) cout << s.substr(center - max_len/2, max_len) << endl;
	else cout << s.substr(center - max_len/2+1, max_len) << endl;
	return 0;
}
