#include <iostream>
#include <string>

using namespace std;

bool v[33][33];
string s[33];

void dfs(int x, int y, int n) {
    if (v[x][y]) return;
    v[x][y] = true;
    if (x > 0 && s[x - 1][y] == '.') dfs(x - 1, y, n);
    if (x < n - 1 && s[x + 1][y] == '.') dfs(x + 1, y, n);
    if (y > 0 && s[x][y - 1] == '.') dfs(x, y - 1, n);
    if (y < n - 1 && s[x][y + 1] == '.') dfs(x, y + 1, n);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, cnt = 0;
    cin >> n;
    getline(cin, s[0]);
    for (int i = 0; i < n; ++i) getline(cin, s[i]);
    dfs(0, 0, n);
    dfs(n - 1, n - 1, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!v[i][j]) continue;
            if (i > 0 && !v[i - 1][j] || i == 0) ++cnt;
            if (i < n - 1 && !v[i + 1][j] || i == n - 1) ++cnt;
            if (j > 0 && !v[i][j - 1] || j == 0) ++cnt;
            if (j < n - 1 && !v[i][j + 1] || j == n - 1) ++cnt;
        }
    }
    cout << (cnt - 4) * 9 << endl;
    return 0;
}