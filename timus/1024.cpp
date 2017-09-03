#include <iostream>
#include <map>
#include <stack>

using namespace std;

bool c[1001][1001];
int n, s[1001];
map<int, int> d;
stack<int> st;

void create_next_set(int cur, int val) {
    if (s[cur] != 0) return;
    s[cur] = val;
    for (int i = 1; i <= n; ++i)
        if (c[i][cur]) create_next_set(i, val);
}

int gcd(int m, int n) {
    int t;
    while (n != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

int lcm(int m, int n) {
    return m / gcd(m, n) * n;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        c[i][a] = c[a][i] = true;
    }
    int p = 1;
    while (p <= n) {
        create_next_set(p, p);
        p = 1;
        while (s[p] != 0 && p <= n) ++p;
    }
    for (int i = 1; i <= n; ++i) ++d[s[i]];
    for (map<int, int>::iterator it = d.begin(); it != d.end(); ++it) st.push(it->second);
    int res = st.top();
    st.pop();
    while (!st.empty()) {
        res = lcm(res, st.top());
        st.pop();
    }
    cout << res << endl;
    return 0;
}