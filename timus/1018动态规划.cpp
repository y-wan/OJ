#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int num[101][101], n, q, p[101], dp[101][100], leaf[101];
bool v[101], dped[101];

void mark_leaf(int par, int cur) {
    v[cur] = true;
    leaf[par] = false;
    leaf[cur] = true;
    p[cur] = par;
    for (int i = 1; i <= n; ++i)
        if (i != cur && !v[i] && num[cur][i] != -1)
            mark_leaf(cur, i);
}

bool is_leaf(int cur) {
    if (cur == 1 || dped[cur]) return false;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (i != cur && num[i][cur] != -1 && !dped[i]) ++cnt;
    return cnt == 1;
}

bool deal_leaf() {
    bool has_leaf = false;
    for (int i = 1; i <= n; ++i) {
        if (is_leaf(i)) {
            has_leaf = true;
            int s1 = -1, s2 = -1;
            for (int j = 2; j <= n; ++j) {
                if (j != p[i] && num[i][j] != -1)
                    if (s1 == -1) s1 = j;
                    else s2 = j;
            }
            if (s1 != -1) {
                for (int j = 1; j <= q; ++j) {
                    dp[i][j] = max(num[i][s1] + dp[s1][j - 1], num[i][s2] + dp[s2][j - 1]);
                    for (int k = 1; k <= j - 1; ++k)
                        dp[i][j] = max(dp[i][j], num[i][s1] + dp[s1][k - 1] + num[i][s2] + dp[s2][j - k - 1]);
                }
            }
            dped[i] = true;
        }
    }
    return has_leaf;
}

void deal_root() {
    int s1 = -1, s2 = -1;
    for (int j = 2; j <= n; ++j) {
        if (j != p[1] && num[1][j] != -1)
            if (s1 == -1) s1 = j;
            else s2 = j;
    }
    dp[1][q] = max(num[1][s1] + dp[s1][q - 1], num[1][s2] + dp[s2][q - 1]);
    for (int k = 1; k <= q - 1; ++k)
        dp[1][q] = max(dp[1][q], num[1][s1] + dp[s1][k - 1] + num[1][s2] + dp[s2][q - k - 1]);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a, b, c;
    memset(num, -1, sizeof(num));
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b >> c;
        num[a][b] = c;
        num[b][a] = c;
    }
    mark_leaf(0, 1);
    while (deal_leaf());
    deal_root();
    cout << dp[1][q] << endl;
    return 0;
}