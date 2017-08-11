#include <iostream>
#include <string>
using namespace std;

int main() {
	int h, w, n, lines = 1, used = 0;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int len = s.size();
		if (len < w - used)
			used += len + 1;
		else if (len == w - used)
			used += len;
		else {
			lines++;
			used = len + 1;
		}
	}
	cout << lines / h + (lines % h > 0) << endl;
	return 0;
}
