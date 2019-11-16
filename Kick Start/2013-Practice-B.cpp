// Problem B. Captain Hammer
// https://code.google.com/codejam/contest/2933486/dashboard#s=p1
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
    cout << fixed << setprecision(10);
    double v, d, theta, theta_deg;
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        cin >> v >> d;
        theta = asin(d*9.8/v/v)/2;
        theta_deg = theta * 180.0 / M_PI;
        cout << "Case #" << tt << ": " << theta_deg << '\n';
    }
    return 0;
}
