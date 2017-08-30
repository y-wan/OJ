#include <iostream>

using namespace std;

int a[100], b[100], c[100];

int main() {
    int n, x;
    cin >> n >> x;
    a[0] = 1;
    b[0] = c[0] = 0;
    if (x == 0) b[0] = c[0] = -1;
    else if (x == 1) c[0] = -1;
    else if (x == 2) b[0] = -1;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        a[i] = a[i - 1] + 1;
        if (b[i - 1] != -1) a[i] = a[i] < b[i - 1] + 1 ? a[i] : b[i - 1] + 1;
        if (c[i - 1] != -1) a[i] = a[i] < c[i - 1] + 1 ? a[i] : c[i - 1] + 1;
        if (x == 0) b[i] = c[i] = -1;
        else if (x == 1) {
            c[i] = -1;
            b[i] = a[i - 1];
            if (c[i - 1] != -1) b[i] = b[i] < c[i - 1] ? b[i] : c[i - 1];
        }
        else if (x == 2) {
            b[i] = -1;
            c[i] = a[i - 1];
            if (b[i - 1] != -1) c[i] = c[i] < b[i - 1] ? c[i] : b[i - 1];
        }
        else {
            b[i] = a[i - 1];
            if (c[i - 1] != -1) b[i] = b[i] < c[i - 1] ? b[i] : c[i - 1];
            c[i] = a[i - 1];
            if (b[i - 1] != -1) c[i] = c[i] < b[i - 1] ? c[i] : b[i - 1];
        }
    }
    if (b[n - 1] != -1) a[n - 1] = a[n - 1] < b[n - 1] ? a[n - 1] : b[n - 1];
    if (c[n - 1] != -1) a[n - 1] = a[n - 1] < c[n - 1] ? a[n - 1] : c[n - 1];
    cout << a[n - 1] << endl;
    return 0;
}

