/*
ID: wanying1
PROG: hamming
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
using namespace std;

int hammingDistance(int a, int b) {
    unsigned int n = a ^ b, count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

bool isCode(int i, const vector<int> &v, int d) {
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        if (hammingDistance(*it, i) < d) return false;
    }
    return true;
}

int main() {
    ofstream fout("hamming.out");
    ifstream fin("hamming.in");
    int n, b, d, cnt = 0;
    fin >> n >> b >> d;
    vector<int> v;
    for (int i = 0; cnt < n; ++i) {
        if (isCode(i, v, d)) {
            v.push_back(i);
            ++cnt;
        }
    }
    int sz = v.size();
    for (int i = 1; i < sz; ++i) {
        if (i % 10 != 0) fout << v[i - 1] << " ";
        else fout << v[i - 1] << endl;
    }
    fout << v[sz - 1] << endl;
    return 0;
}
