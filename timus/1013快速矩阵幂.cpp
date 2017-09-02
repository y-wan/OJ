#include <iostream>

using namespace std;
long long base[2][2], res[2][2];

long long long_long_multiply(long long a, long long b, long long mod) {
    long long res = 0;
    if (b != 0) {
        if (b & 1) res = a % mod;
        res = (res + (long_long_multiply(a, b >> 1, mod) << 1 ) % mod) % mod;
    }
    return res;
}

void matrix_multiply(long long a[2][2], long long b[2][2], long long mod) {
    long long c[2][2];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            c[i][j] = (long_long_multiply(a[i][0], b[0][j], mod) + long_long_multiply(a[i][1], b[1][j], mod)) % mod;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            a[i][j] = c[i][j];
}

void matrix_power(long long res[2][2], long long base[2][2], long long p, long long mod) {
    if (p & 1) matrix_multiply(res, base, mod);
    if (p > 1) {
        p >>= 1;
        matrix_multiply(base, base, mod);
        matrix_power(res, base, p, mod);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long n, k, m, f2;
    cin >> n >> k >> m;
    f2 = long_long_multiply(k, k - 1, m);
    base[0][0] = base[0][1] = k - 1, base[1][0] = 1;
    res[0][0] = res[1][1] = 1;
    if (n > 2) matrix_power(res, base, n - 2, m);
    cout << (long_long_multiply(res[0][0], f2, m) + long_long_multiply(res[0][1], k - 1, m)) % m << endl;
    return 0;
}