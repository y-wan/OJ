#include <iostream>
#include <cstring>

using namespace std;

const int N = 51, S = 501;
char d[N][S][110], a[110], b[110], res[110];
int sum[110];

char* add(char* s, char* t) {
    int ns = strlen(s), nt = strlen(t);
    if (ns == 0) return t;
    else if (nt == 0) return s;
    int n = ns > nt ? ns : nt;
    memset(res, '\0', sizeof(res));
    memset(a, '\0', sizeof(a));
    memset(b, '\0', sizeof(b));
    memset(sum, 0, sizeof(sum));
    memset(a, '0', sizeof(char) * (n - ns));
    memcpy(a + n - ns, s, sizeof(char) * (ns + 1));
    memset(b, '0', sizeof(char) * (n - nt));
    memcpy(b + n - nt, t, sizeof(char) * (nt + 1));
    for (int i = n; i > 0; --i) sum[i] = (a[i - 1] - '0') + (b[i - 1] - '0');
    for (int i = n; i > 0; --i) {
        sum[i - 1] += sum[i] / 10;
        sum[i] %= 10;
    }
    if (sum[0] != 0) for (int i = 0; i <= n; ++i) res[i] = sum[i] + '0';
    else for (int i = 0; i < n; ++i) res[i] = sum[i + 1] + '0';
    return res;
}

char* squared(char* s) {
    int n = strlen(s);
    if (n == 0) {
        res[0] = '0';
        return res;
    }
    memset(res, '\0', sizeof(char) * 110);
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            sum[i + j + 1] += (s[i] - '0')*(s[j] - '0');
    for (int i = 2*n - 1; i > 0; --i) {
        sum[i - 1] += sum[i] / 10;
        sum[i] %= 10;
    }
    if (sum[0] != 0) for (int i = 0; i < 2*n; ++i) res[i] = sum[i] + '0';
    else for (int i = 0; i < 2*n - 1; ++i) res[i] = sum[i + 1] + '0';
    return res;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, s;
    cin >> n >> s;
    if (s & 1 || 18 * n < s) {
        cout << "0\n";
        return 0;
    }
    s >>= 1;
    for (int i = 0; i < 10; ++i) memcpy(d[1][i], "1", sizeof("1"));
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            for (int k = 0; k < 10 && j - k >= 0; ++k) {
                memcpy(d[i][j], add(d[i][j], d[i - 1][j - k]), sizeof(char) * 110);
            }
        }
    }
    cout << squared(d[n][s]) << endl;
    return 0;
}