#include <iostream>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    double p, q;
    int res = 2;
    cin >> p >> q;
    while ((int)(p* (double)res + (1e-7)) / 100 == (int)(q* (double)res - (1e-7)) / 100)
        ++res;
    cout << res << endl;
    return 0;
}