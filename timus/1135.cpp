#include <iostream>
#include <string>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, cnt = 0, res = 0, len = 0;
    string s;
    cin >> n;
    while (len < n) {
        cin >> s;
        m = s.size();
        len += m;
        for (int i = 0; i < m; ++i)
            s[i] == '>' ? ++cnt : res += cnt;
    }
    cout << res << endl;
    return 0;
}