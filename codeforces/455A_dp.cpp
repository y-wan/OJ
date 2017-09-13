#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    vector<long long> v(100001, 0), dp(100001, 0);
    int n, t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        v[t] += t;
    }
    dp[0] = 0;
    dp[1] = v[1];
    for (int i = 2; i <= 100000; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
    }
    cout << dp[100000] << endl;
    return 0;
}