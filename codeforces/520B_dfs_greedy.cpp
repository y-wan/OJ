#include <iostream>

using namespace std;

int depth[10001];

void dfs(int n, int m, int d) {
    if (depth[n] != 0 && d > depth[n]) return;
    depth[n] = d;
    int t = 0;
    if (n >= m) {
        if (depth[m] == 0 || d + n - m < depth[m]) depth[m] = d + n - m;
        return;
    }
    else {
        if (n <= 5000) dfs(n * 2, m, d + 1);
        if (n > 1) dfs(n - 1, m, d + 1);
    }
}

int main() {
    int n, m, t = 0;
    cin >> n >> m;
    depth[n] = 1;
    dfs(n, m, 1);
    cout << depth[m] - 1 << endl;
    return 0;
}