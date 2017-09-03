#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

bool a[11][11], v[11][11];
queue<pair<int, int> > q;
int cnt, n;

void print_rtlb(int x, int y) {
    if (x < 10 && a[x + 1][y] && !v[x + 1][y]) {
        cout << 'R';
        v[x + 1][y] = true;
        q.push(make_pair(x + 1, y));
    }
    if (y < 10 && a[x][y + 1] && !v[x][y + 1]) {
        cout << 'T';
        v[x][y + 1] = true;
        q.push(make_pair(x, y + 1));
    }
    if (x > 1 && a[x - 1][y] && !v[x - 1][y]) {
        cout << 'L';
        v[x - 1][y] = true;
        q.push(make_pair(x - 1, y));
    }
    if (y > 1 && a[x][y - 1] && !v[x][y - 1]) {
        cout << 'B';
        v[x][y - 1] = true;
        q.push(make_pair(x, y - 1));
    }
    if (++cnt < n) cout << ",\n";
    else cout << ".\n";
    if (!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();
        print_rtlb(x, y);
    }
}

void print_digit() {
    for (int i = 1; i < 11; ++i)
        for (int j = 1; j < 11; ++j)
            if (a[i][j]) cout << i << ' ' << j << endl;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string s;
    getline(cin, s);
    stringstream ss(s);
    if (s.find(' ') == string::npos) {
        int x0, y0, x, y;
        ss >> n;
        cin >> x0 >> y0;
        a[x0][y0] = true;
        for (int i = 1; i < n; ++i) {
            cin >> x >> y;
            a[x][y] = true;
        }
        cout << x0 << ' ' << y0 << endl;
        v[x0][y0] = true;
        print_rtlb(x0, y0);
    }
    else {
        int x, y, len;
        ss >> x >> y;
        a[x][y] = true;
        ++n;
        q.push(make_pair(x, y));
        do {
            cin >> s;
            len = s.size();
            x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < len - 1; ++i) {
                switch (s[i]) {
                case 'R': a[x + 1][y] = true; q.push(make_pair(x + 1, y)); ++n; break;
                case 'T': a[x][y + 1] = true; q.push(make_pair(x, y + 1)); ++n; break;
                case 'L': a[x - 1][y] = true; q.push(make_pair(x - 1, y)); ++n; break;
                case 'B': a[x][y - 1] = true; q.push(make_pair(x, y - 1)); ++n; break;
                default: break;
                }
            }
        } while (s[len - 1] != '.');
        cout << n << endl;
        print_digit();
    }
    return 0;
}