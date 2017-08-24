#include <iostream>
#include <algorithm>

using namespace std;

int a[100], b[100], n, m, res;
bool va[100], vb[100];

void dfs(int p, int q) {
    int t = q;
    while (p < n) {
        q = t;
        while (q < m && !(a[p] - b[q] <= 1 && b[q] - a[p] <= 1)) ++q;
        while (q < m && a[p] - b[q] <= 1 && b[q] - a[p] <= 1) {
            if (!va[p] && !vb[q]) {
                ++res;
                va[p] = true;
                vb[q] = true;
                dfs(++p, ++q);
            }
            else ++q;
        }
        ++p;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    dfs(0, 0);
    cout << res << endl;
    return 0;
}
