#include <iostream>

using namespace std;

long long gcd(long long m, long long n) {
    long long t;
    while (n > 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    long long a, b;
    cin >> n >> a;
    for (int i = 1; i < n; ++i) {
        cin >> b;
        a = gcd(a, b);
    }
    cout << a << endl;
    return 0;
}