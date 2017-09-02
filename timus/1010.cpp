#include <iostream>
#define ABS(a) ((a)>0?(a):(-(a)))

using namespace std;

long long y[100001];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, x1 = 2, x2;
    cin >> n >> y[1] >> y[2];
    double k1 = double(y[2] - y[1]), k2;
    for (int i = 3; i <= n; ++i) {
        cin >> y[i];
        if (ABS(y[i] - y[i - 1]) - 1e-10 > k1) {
            k1 = ABS(y[i] - y[i - 1]);
            x1 = i;
        }
    }
    cout << x1 - 1 << " " << x1 << endl;
    return 0;
}