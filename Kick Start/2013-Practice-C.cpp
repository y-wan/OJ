// Problem C. Moist
// https://code.google.com/codejam/contest/2933486/dashboard#s=p2
#include <iostream>

using namespace std;

int main() {
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    int T, n, res;
    string s, ma;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n;
        getline(cin, ma);
        res = 0;
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            if (s < ma) {
                ++res;
            } else {
                ma = s;
            }
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
    return 0;
}
