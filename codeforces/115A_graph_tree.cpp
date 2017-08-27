#include <iostream>

using namespace std;

int sup[2001], d[2001];

int main() {
    int n, t, m = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> sup[i];
        d[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (sup[i] != -1) {
            int tmp = i, dep = 1;
            do {
                ++dep;
                if (dep > d[tmp]) d[tmp] = dep;
                else dep = d[tmp];
                tmp = sup[tmp];
            } while (sup[tmp] != -1);
            m = m > dep ? m : dep;
        }
    }
    cout << m << endl;
    return 0;
}

