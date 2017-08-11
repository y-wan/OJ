#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, mod, res = 1;
	string s;
	cin >> n >> s;
	mod = s.size();
	while (n > 0) {
		res *= n;
		n -= mod;
	}
	cout << res << endl;
	return 0;
}
