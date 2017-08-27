#include <iostream>
#include <algorithm>

using namespace std;

int a[100000], s[100000];

int main() {
    int n, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    s[0] = a[0];
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] > a[i]) s[i] = s[i - 1];
        else {
            s[i] = s[i - 1] + a[i];
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}

