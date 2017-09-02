#include <iostream>
#include <cstring>

using namespace std;

int color[100], n;
bool c[100][100], v[100], pos = true;

void dfs(int cur, int val) {
    if (!pos) return;
    if (color[cur] == (val ^ 1)) {
        pos = false;
        return;
    }
    if (color[cur] == val) return;
    v[cur] = true;
    color[cur] = val;
    for (int i = 1; i <= n; ++i)
        if (i != cur && c[cur][i] && pos) dfs(i, val ^ 1);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int j;
    memset(color, -1, sizeof(color));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        while (cin >> j && j) {
            c[i][j] = true;
            c[j][i] = true;
        }
    }
    dfs(1, 0);
    for (int i = 2; i <= n && pos; ++i)
        if (!v[i]) dfs(i, 0);
    if (!pos) cout << "-1\n";
    else {
        for (int i = 1; i <= n; ++i) cout << color[i];
        cout << endl;
    }
    return 0;
}