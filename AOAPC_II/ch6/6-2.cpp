#include <iostream>
#include <string>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, pos, kase = 0, a[8];
    string s, t;
    while (cin >> n && n) {
        cout << "S-Tree #" << ++kase << ":\n";
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            a[i] = s[1] - '0';
        }
        cin >> t >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> s;
            pos = 0;
            for (int j = 1; j <= n; ++j) {
                pos <<= 1;
                if (s[a[j] - 1] == '1') ++pos;
            }
            cout << t[pos];
        }
        cout << endl << endl;
    }
    return 0;
}