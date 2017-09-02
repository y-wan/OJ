#include <iostream>

using namespace std;
long long a[44];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    a[0] = 1, a[1] = 2;
    for (int i = 2; i < 44; ++i) a[i] = a[i - 1] + a[i - 2];
    int n;
    long long k;
    cin >> n >> k;
    if (k > a[n]) {
        cout << "-1\n";
        return 0;
    }
    while (k > 0 && n > 0) {
        if (k > a[n - 1]) {
            cout << "1";
            if (n > 1) cout << "0";
            k -= a[n - 1];
            n -= 2;
        }
        else {
            cout << "0";
            --n;
        }
    }
    cout << endl;
    return 0;
}