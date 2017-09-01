#include <iostream>

using namespace std;

bool is_prime(long long n) {
    for (long long i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long n;
    cin >> n;
    if (n == 4) {
        cout << "3\n";
        return 0;
    }
    else if (n % 2 == 0 && is_prime(n / 2)) {
        cout << n / 2 - 1 << endl;
        return 0;
    }
    else {
        for (long long i = 2; i * i <= n; ++i) {
            if (n % (i + 1) == 0) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << n - 1 << endl;
    return 0;
}