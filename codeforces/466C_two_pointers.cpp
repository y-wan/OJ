#include <iostream>
#include <stack>

using namespace std;

long long a[500002], rt[500002];
stack<int> lt;

int main() {
    int n, p = 0;
    long long t, sum = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0) {
        cout << "0\n";
        return 0;
    }
    sum /= 3;
    t = 0;
    for (int i = 1; i <= n - 2; ++i) {
        t += a[i];
        if (t == sum) lt.push(i);
    }
    t = 0;
    for (int i = n; i >= 3; --i) {
        t += a[i];
        if (t == sum) rt[i] = rt[i + 1] + 1;
        else rt[i] = rt[i + 1];
    }
    while (!lt.empty()) {
        t = lt.top();
        cnt += rt[t + 2];
        lt.pop();
    }
    cout << cnt << endl;
    return 0;
}

