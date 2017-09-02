#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

string d[105][105];
int c[105][105];
map<char, char> dict;

void add_d(const string & s, const string & w) {
    int n = s.size(), m = w.size();
    bool add;
    for (int i = 0; i <= n - m; ++i) {
        add = true;
        for (int j = 0; j < m; ++j) {
            if (s[i + j] != dict[w[j]]) {
                add = false;
                break;
            }
        }
        if (add) {
            d[i][i + m - 1] = w + ' ';
            c[i][i + m - 1] = 1;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string s, w;
    int num, n;
    /*
    1 ij    2 abc   3 def
    4 gh    5 kl    6 mn
    7 prs   8 tuv   9 wxy
        0 oqz*/
    dict['a'] = '2';
    dict['b'] = '2';
    dict['c'] = '2';
    dict['d'] = '3';
    dict['e'] = '3';
    dict['f'] = '3';
    dict['g'] = '4';
    dict['h'] = '4';
    dict['i'] = '1';
    dict['j'] = '1';
    dict['k'] = '5';
    dict['l'] = '5';
    dict['m'] = '6';
    dict['n'] = '6';
    dict['o'] = '0';
    dict['p'] = '7';
    dict['q'] = '0';
    dict['r'] = '7';
    dict['s'] = '7';
    dict['t'] = '8';
    dict['u'] = '8';
    dict['v'] = '8';
    dict['w'] = '9';
    dict['x'] = '9';
    dict['y'] = '9';
    dict['z'] = '0';
    while (cin >> s && s[0] != '-') {
        n = s.size();
        memset(d, '\0', sizeof(d));
        memset(c, -1, sizeof(c));
        cin >> num;
        for (int i = 0; i < num; ++i) {
            cin >> w;
            add_d(s, w);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                for (int k = 0; k < i; ++k) {
                    if (c[j][j + k] == -1 || c[j + k + 1][j + i] == -1) continue;
                    if (c[j][j + i] == -1 || c[j][j + i] > c[j][j + k] + c[j + k + 1][j + i]) {
                        c[j][j + i] = c[j][j + k] + c[j + k + 1][j + i];
                        d[j][j + i] = d[j][j + k] + d[j + k + 1][j + i];
                    }
                }
            }
        }
        if (c[0][n - 1] == -1) cout << "No solution.\n";
        else cout << d[0][n - 1].substr(0, d[0][n - 1].size() - 1) << endl;
    }
    return 0;
}