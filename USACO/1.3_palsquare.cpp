/*
ID: wanying1
PROG: palsquare
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

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int n;
    fin >> n;
	for (int i = 1; i <= 300; ++i) {
		string squared = toBase(i*i, n);
		if (isPal(squared)) fout << toBase(i, n) << " " << squared << endl;
	}
    return 0;
}