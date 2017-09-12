#include <iostream>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int m, d1, d2;
    cin >> m >> d1 >> d2;
    int a = m * d1 / d2, b = m * d1 % d2;
    for (int i = 0; i < d2; ++i)
        cout << (i < b ? a + 1 : a) << ' ';
    cout << endl;
    return 0;
}