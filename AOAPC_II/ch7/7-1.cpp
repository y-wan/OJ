#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

//stack<int> d;
bool c[21][21], v[21], connect[21];
vector<int> d;
int cnt_print;

void print_d(int goal) {
    cout << 1;
    for (int j = 1; d[j]; ++j) cout << ' ' << d[j];
    cout << '\n';
}

void mark_connect(const int n, const int ma) {
    connect[n] = true;
    for (int i = 1; i <= ma; ++i) {
        if (c[i][n] && !connect[i]) {
            mark_connect(i, ma);
        }
    }
}

void bfs(const int n, const int len_d, const int ma) {
    if (d[len_d - 1] == n) {
        print_d(n);
        ++cnt_print;
        return;
    }
    if (len_d >= ma) return;
    for (int i = 2; i <= ma; ++i) {
        if (!v[i] && connect[i] && c[d[len_d - 1]][i]) {
            v[i] = !v[i];
            d[len_d] = i;
            bfs(n, len_d + 1, ma);
            v[i] = !v[i];
            d[len_d] = 0;
        }
    }
}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // _DEBUG
    ios::sync_with_stdio(false);
    int kase = 0, n, p, q, ma;
    d.resize(20);
    while (cin >> n) {
        //d.clear();
        d[0] = 1;
        ma = 0;
        for (int i = 1; i < 20; ++i) d[i] = 0;
        memset(c, false, sizeof(c));
        memset(connect, false, sizeof(connect));
        memset(v, false, sizeof(v));
        cnt_print = 0;
        v[1] = true;
        while (cin >> p >> q && p) {
            c[p][q] = true;
            c[q][p] = true;
            ma = ma > p ? ma : p;
            ma = ma > q ? ma : q;
        }
        cout << "CASE " << ++kase << ":\n";
        mark_connect(n, ma);
        bfs(n, 1, ma);
        cout << "There are " << cnt_print << " routes from the firestation to streetcorner " << n << ".\n";
    }
    return 0;
}