#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

bool v[8][8];
queue<pair<pair<int, int>, int> > q;
int res = -1;

void bfs(const int r1, const int c1, const int r2, const int c2, const int dep) {
    if (res != -1) return; 
    v[r1][c1] = true;
    if (r1 == r2 && c1 == c2) {
        res = dep;
        return;
    }
    if (r1 - 2 >= 0 && c1 - 1 >= 0 && !v[r1 - 2][c1 - 1]) q.push(make_pair(make_pair(r1 - 2, c1 - 1), dep + 1));
    if (r1 - 1 >= 0 && c1 - 2 >= 0 && !v[r1 - 1][c1 - 2]) q.push(make_pair(make_pair(r1 - 1, c1 - 2), dep + 1));
    if (r1 - 2 >= 0 && c1 + 1 < 8 && !v[r1 - 2][c1 + 1]) q.push(make_pair(make_pair(r1 - 2, c1 + 1), dep + 1));
    if (r1 - 1 >= 0 && c1 + 2 < 8 && !v[r1 - 1][c1 + 2]) q.push(make_pair(make_pair(r1 - 1, c1 + 2), dep + 1));
    if (r1 + 2 < 8 && c1 - 1 >= 0 && !v[r1 + 2][c1 - 1]) q.push(make_pair(make_pair(r1 + 2, c1 - 1), dep + 1));
    if (r1 + 1 < 8 && c1 - 2 >= 0 && !v[r1 + 1][c1 - 2]) q.push(make_pair(make_pair(r1 + 1, c1 - 2), dep + 1));
    if (r1 + 2 < 8 && c1 + 1 < 8 && !v[r1 + 2][c1 + 1]) q.push(make_pair(make_pair(r1 + 2, c1 + 1), dep + 1));
    if (r1 + 1 < 8 && c1 + 2 < 8 && !v[r1 + 1][c1 + 2]) q.push(make_pair(make_pair(r1 + 1, c1 + 2), dep + 1));
    while (res == -1 && !q.empty()) {
        pair<pair<int, int>, int> tmp = q.front();
        q.pop();
        bfs(tmp.first.first, tmp.first.second, r2, c2, tmp.second);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int r1, r2, c1, c2;
    string s, t;
    while (cin >> s >> t) {
        r1 = s[0] - 'a', r2 = s[1] - '1', c1 = t[0] - 'a', c2 = t[1] - '1';
        bfs(r1, r2, c1, c2, 0);
        cout << "To get from " << s << " to " << t << " takes " << res << " knight moves.\n";
        memset(v, false, sizeof(v));
        while (!q.empty()) q.pop();
        res = -1;
    }
    return 0;
}