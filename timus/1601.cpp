#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	//ios_base::sync_with_stdio(false);
	string s;
	bool cap = true;
	while (getline(cin, s)) {
		string s1 = s;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (isalpha(s[i])) {
				if (cap) cap = false;
				else s1[i] = s[i] - 'A' + 'a';
			}
			else if (s[i] == '.' || s[i] == '!' || s[i] == '?') cap = true;
		}
		cout << s1 << endl;
	}
	return 0;
}
