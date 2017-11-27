/*
ID: wanying1
PROG: dualpal
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <string>

using namespace std;

string convert(int n) {
	if (n < 10) return string(1, '0' + n);
	return string(1, 'A' + n - 10);
}

string toBase(int n, int base) {
	string ret = "";
	while (n) {
		int res = n % base;
		n /= base;
		ret = convert(res) + ret;
	}
	return ret;
}

bool isPal(string s) {
	int n = s.length();
	for (int i = 0; i < n; ++i) {
		if (s[i] != s[n - 1 - i]) return false;
	}
	return true;
}

bool isDualPal(int n) {
	int cnt = 0;
	for (int i = 2; i <= 10; ++i) {
		if (isPal(toBase(n, i))) ++cnt;
		if (cnt >= 2) return true;
	}
	return false;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int n, s;
    fin >> n >> s;
	while (n > 0) {
		++s;
		if (isDualPal(s)) {
			fout << s << endl;
			--n;
		}
	}
    return 0;
}