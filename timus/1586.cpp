#include <iostream>
#include <cmath>

using namespace std;

long long dp[10001][10][10];
const int MOD = 1e9 + 9;
bool flag[1000];

bool is_prime(int n) {  // n >= 3
    int m = int(sqrt(n) + 1);
    for (int i = 2; i <= m; ++i)
        if (n % i == 0)
            return false;
    return true;
}

void init_flag() {
    for (int i = 100; i < 1000; ++i)
        if (is_prime(i))
            flag[i] = true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    init_flag();
    int n;
    cin >> n;
    for (int i = 100; i < 1000; ++i)
        if (flag[i])
            dp[3][i / 100][i % 100 / 10]++;
    for (int i = 4; i <= n; ++i) {
        for (int j = 1; j <= 9; ++j) {
            for (int k = 0; k < 10; ++k) {
                for (int l = 0; l < 10; ++l) {
                    if (flag[j * 100 + k * 10 + l]) {
                        dp[i][j][k] += dp[i - 1][k][l];
                        dp[i][j][k] %= MOD;
                    }
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            sum += dp[n][i][j];
            sum %= MOD;
        }
    }
    cout << sum << endl;
    return 0;
}