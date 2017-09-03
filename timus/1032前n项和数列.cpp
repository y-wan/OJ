#include <iostream>

using namespace std;

int s[10001], a[10001];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] % n == 0) {
            cout << "1\n" << a[i] << endl;
            return 0;
        }
        s[i] = (s[i - 1] + a[i]) % n;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (s[i] == s[j]) {
                cout << j - i << endl;
                for (int k = i + 1; k <= j; ++k) cout << a[k] << endl;
                return 0;
            }
        }
    }
    return 0;
}