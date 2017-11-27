/*
ID: wanying1
PROG: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
	string sa, sb;
    int a = 1, b = 1;
    fin >> sa >> sb;
	for (string::iterator it = sa.begin(); it != sa.end(); ++it) {
		a *= *it - 'A' + 1;
		a %= 47;
	}
	for (string::iterator it = sb.begin(); it != sb.end(); ++it) {
		b *= *it - 'A' + 1;
		b %= 47;
	}
    fout << (a == b ? "GO":"STAY") << endl;
    return 0;
}