/*
ID: wanying1
PROG: frac1
LANG: C++11
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ofstream fout("frac1.out");
    ifstream fin("frac1.in");
    int n;
    fin >> n;
    vector<pair<double, string> > v;
    for (int den = 1; den <= n; ++den) {
        for (int num = 0; num <= den; ++num) {
            if (gcd(num, den) == 1) {
                v.push_back(make_pair(static_cast<double>(num)/den, to_string(num)+"/"+to_string(den)));
            }
        }
    }
    sort(v.begin(), v.end());
    for (vector<pair<double, string> >::iterator it = v.begin(); it != v.end(); ++it)
        fout << it->second << endl;
    return 0;
}
