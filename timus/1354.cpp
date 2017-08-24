#include <iostream>
#include <string>

using namespace std;

int main() {
	bool even = false;
	int center = -1;
	string s;
	cin >> s;
	int len = s.size();
	if (s.size() == 1) {
		cout << s << s << endl;
		return 0;
	}
	for (int i = 1; i < len; ++i) {
		int p = i;
		while (s[p] == s[len - 1 - p + i] && p <= len - 1 - p + i) ++p;
		--p;
		if (p + 1 == len - 1 - p + i) {
			even = true;
			center = p;
			break;
		}
		else if (p == len - 1 - p + i) {
			center = p;
			break;
		}
	}
	if (!even) {
		for (int i = 0; i <= center; ++i) cout << s[i];
		for (int i = center - 1; i >= 0; --i) cout << s[i];
	}
	else {
		for (int i = 0; i <= center; ++i) cout << s[i];
		for (int i = center; i >= 0; --i) cout << s[i];
	}
	cout << endl;
	return 0;
}
