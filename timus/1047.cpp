#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    double a0, an1, c, res = 0.0;
    cin >> n >> a0 >> an1;
    res = an1 + n*a0;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        res -= 2 * (n + 1 - i)*c;
    }
    printf("%.2f\n", res / (n + 1));
    return 0;
}