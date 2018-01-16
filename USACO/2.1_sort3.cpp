/*
ID: wanying1
PROG: sort3
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ofstream fout("sort3.out");
    ifstream fin("sort3.in");
    int n, ans = 0, rep = 0;
    fin >> n;
    vector<int> v(n), cnt(3, 0);
    for (int i = 0; i < n; ++i) {
        fin >> v[i];
        ++cnt[v[i] - 1];
    }
    for (int i = 0; i < cnt[0]; ++i) {
        if (v[i] != 1) {
            ++ans;
            if (v[i] == 3) ++rep;
        }
    }
    for (int i = n - 1; i >= n - cnt[2]; --i) {
        if (v[i] != 3) {
            if (v[i] == 2) ++ans;
            else if (rep > 0) --rep;
            else ++ans;
        }
    }    
    fout << ans << endl;
    return 0;
}
