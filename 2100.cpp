#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	int sum = n + 2;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[s.size() - 4] == '+') sum++;
	}
	if (sum == 13) sum++;
	cout << 100 * sum << endl;
	return 0;
}
