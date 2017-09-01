#include <cstring>
#include <cstdio>

using namespace std;

char a[1800][1800];
int tmp[1800];
char add_str[1800], mul_str[1800];

char* mul(char *s, int d) {
    memset(mul_str, '\0', sizeof(mul_str));
    memset(tmp, 0, sizeof(tmp));
    int n = strlen(s);
    for (int i = 0; i < n; ++i) tmp[i] = (s[n - 1 - i] - '0') * d;
    for (int i = 0; i < n; ++i) {
        if (tmp[i] >= 10) {
            tmp[i + 1] += tmp[i] / 10;
            tmp[i] %= 10;
        }
    }
    if (tmp[n] != 0) for (int i = 0; i <= n; ++i) mul_str[i] = char(tmp[n - i] + '0');
    else for (int i = 0; i < n; ++i) mul_str[i] = char(tmp[n - 1 - i] + '0');
    return mul_str;
}

char* add(char* s, char* t) {
    memset(add_str, '\0', sizeof(add_str));
    memset(tmp, 0, sizeof(tmp));
    int ns = strlen(s), nt = strlen(t), n = ns > nt ? ns : nt, ds = n - ns, dt = n - nt;
    for (int i = 0; i < n; ++i) {
        if (n - 1 - i - ds >= 0) tmp[i] += (s[n - 1 - i - ds] - '0');
        if (n - 1 - i - dt >= 0) tmp[i] += (t[n - 1 - i - dt] - '0');
    }
    for (int i = 0; i < n; ++i) {
        if (tmp[i] >= 10) {
            tmp[i + 1] += tmp[i] / 10;
            tmp[i] %= 10;
        }
    }
    if (tmp[n] != 0) for (int i = 0; i <= n; ++i) add_str[i] = char(tmp[n - i] + '0');
    else for (int i = 0; i < n; ++i) add_str[i] = char(tmp[n - 1 - i] + '0');
    return add_str;
}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // _DEBUG
    int n, k;
    scanf("%d%d", &n, &k);
    a[1][0] = k - 1 + '0';
    int t = k * (k - 1);
    if (t < 10) a[2][0] = t + '0';
    else {
        a[2][0] = t / 10 + '0';
        a[2][1] = t % 10 + '0';
    }
    for (int i = 3; i <= n; ++i) {
        mul(add(a[i - 1], a[i - 2]), k - 1);
        memcpy(a[i], mul_str, sizeof(mul_str));
    }
    printf("%s\n", a[n]);
    return 0;
}