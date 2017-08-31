#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

bool v[20][20], ob[20][20];
queue<pair<pair<int, int>, pair<int, int>> > q;
int mk[20][20], m, n, k, res = -1;

void bfs(const int r1, const int c1, const int r2, const int c2, const int c, const int dep) {
    if (res != -1 || c >= mk[r1][c1]) return; 
    v[r1][c1] = true;
    mk[r1][c1] = c;
    if (r1 == r2 && c1 == c2) {
        res = dep;
        return;
    }
    int tmp;
    if (c1 - 1 >= 0) {
        tmp = ob[r1][c1 - 1] ? c + 1 : 0;
        if ((!v[r1][c1 - 1] || tmp < mk[r1][c1 - 1]) && c + ob[r1][c1 - 1] <= k)
            q.push(make_pair(make_pair(r1, c1 - 1), make_pair(tmp, dep + 1)));
    }
    if (c1 + 1 < n) {
        tmp = ob[r1][c1 + 1] ? c + 1 : 0;
        if ((!v[r1][c1 + 1] || tmp < mk[r1][c1 + 1]) && c + ob[r1][c1 + 1] <= k)
            q.push(make_pair(make_pair(r1, c1 + 1), make_pair(tmp, dep + 1)));
    }
    if (r1 - 1 >= 0) {
        tmp = ob[r1 - 1][c1] ? c + 1 : 0;
        if ((!v[r1 - 1][c1] || tmp < mk[r1 - 1][c1]) && c + ob[r1 - 1][c1] <= k)
            q.push(make_pair(make_pair(r1 - 1, c1), make_pair(tmp, dep + 1)));
    }
    if (r1 + 1 < m) {
        tmp = ob[r1 + 1][c1] ? c + 1 : 0;
        if ((!v[r1 - 1][c1] || tmp < mk[r1 + 1][c1]) && c + ob[r1 + 1][c1] <= k)
            q.push(make_pair(make_pair(r1 + 1, c1), make_pair(tmp, dep + 1)));
    }
    while (res == -1 && !q.empty()) {
        pair<pair<int, int>, pair<int, int>> tmp_p = q.front();
        q.pop();
        bfs(tmp_p.first.first, tmp_p.first.second, r2, c2, tmp_p.second.first, tmp_p.second.second);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int kase;
    cin >> kase;
    while (kase-- > 0) {
        cin >> m >> n >> k;
        memset(v, false, sizeof(v));
        while (!q.empty()) q.pop();
        res = -1;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) mk[i][j] = k + 1;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> ob[i][j];
        bfs(0, 0, m - 1, n - 1, 0, 0);
        cout << res << endl;
    }
    return 0;
}