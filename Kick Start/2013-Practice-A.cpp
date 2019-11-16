// Problem A. Bad Horse
// https://code.google.com/codejam/contest/2933486/dashboard#s=p0
// 并查集，参考：https://blog.csdn.net/u013446688/article/details/39803733
#include <iostream>
#include <map>

using namespace std;

map<string, string> parent;

string getParent(const string& n) {
    if (parent.find(n) == parent.end()) {
        parent[n] = n;
        return n;
    }
    string p = parent[n], res, tmp;
    while (parent[p] != p) p = parent[p];
    res = p;
    p = n;
    while (p != res) {
        tmp = parent[p];
        parent[p] = res;
        p = tmp;
    }
    return res;
}

void add(const string& s1, const string& s2) {
    string p1 = getParent(s1), p2 = getParent(s2);
    if (p1 != p2) parent[p1] = p2;
}

int main() {
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    int T, m;
    string s1, s2, ans;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        parent.clear();
        ans = "Yes";
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> s1 >> s2;
            if (getParent(s1) == getParent(s2) || getParent('^' + s1) == getParent('^' + s2)) {
                ans = "No";
            } else {
                add(s1, '^' + s2);
                add(s2, '^' + s1);
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
