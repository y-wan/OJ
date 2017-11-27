/*
ID: wanying1
PROG: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>

using namespace std;

int commonCnt[7] = { 2, 1, 1, 3, 1, 2, 2 }, leapCnt[7] = { 3, 1, 1, 2, 2, 1, 2 }, ans[7];

bool isLeap(int n) {
	if (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0)) return true;
	return false;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n, start = 0;
    fin >> n;
	for (int i = 0; i < n; ++i) {
		int year = 1900 + i;
		if (isLeap(year)) {
			for (int j = 0; j < 7; ++j) {
				ans[(start + j) % 7] += leapCnt[j];
			}
			start += 2;
		}
		else {
			for (int j = 0; j < 7; ++j) {
				ans[(start + j) % 7] += commonCnt[j];
			}
			++start;
		}
	}
	for (int i = 0; i < 6; ++i)
		fout << ans[i] << " ";
	fout << ans[6] << endl;
    return 0;
}