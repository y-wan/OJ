/*
ID: wanying1
PROG: numtri
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout("numtri.out");
    ifstream fin("numtri.in");
    int n;
    fin >> n;
    vector<vector<int> > sum(2, vector<int>(n, 0));
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j)
            fin >> v[j];
        sum[i % 2][0] = v[0] + sum[(i + 1) % 2][0];
        for (int j = 1; j < i - 1; ++j)
            sum[i % 2][j] = v[j] + max(sum[(i + 1) % 2][j - 1], sum[(i + 1) % 2][j]);
        sum[i % 2][i - 1] = v[i - 1] + sum[(i + 1) % 2][max(0, i - 2)];
    }
    int ans = sum[n % 2][0];
    for (int i = 1; i < n; ++i)
        ans = max(ans, sum[n % 2][i]);
    fout << ans << endl;
    return 0;
}
