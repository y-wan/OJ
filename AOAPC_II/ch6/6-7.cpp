#include <iostream>
#include <cstring>

using namespace std;

int p[100], tin[100][100], tout[100][100], np, nt, nf, pin[100], pout[100];

bool transite(int pt) {
    memset(pin, 0, sizeof(pin));
    memset(pout, 0, sizeof(pout));
    for (int i = 1; i < 100; ++i) {
        ++pin[tin[pt][i]];
        ++pout[tout[pt][i]];
    }
    for (int i = 1; i < 100; ++i)
        if (p[i] < pin[i] - pout[i])
            return false;
    for (int i = 1; i < 100; ++i)
        p[i] -= pin[i] - pout[i];
    return true;
}

void print_status() {
    cout << "Places with tokens:";
    for (int i = 1; i <= np; ++i)
        if (p[i] > 0)
            cout << " " << i << " (" << p[i] << ")";
    cout << "\n\n";
}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // _DEBUG
    int tmp, p1, p2, kase = 0;
    while (cin >> np && np) {
        ++kase;
        memset(p, 0, sizeof(p));
        memset(tin, 0, sizeof(tin));
        memset(tout, 0, sizeof(tout));
        for (int i = 1; i <= np; ++i) cin >> p[i];
        cin >> nt;
        for (int i = 1; i <= nt; ++i) {
            p1 = 1; p2 = 1;
            while (cin >> tmp && tmp) {
                if (tmp < 0) tin[i][p1++] = -tmp;
                else tout[i][p2++] = tmp;
            }
        }
        cin >> nf;
        tmp = 0; // # of successful transitions
        p1 = 1;
        int last = 0; // # of continuous failed transitions
        bool ptd = false;
        while (tmp < nf && !ptd) {
            if (!transite(p1)) {
                if (++last >= nt) {
                    cout << "Case " << kase << ": dead after " << tmp << " transitions\n";
                    print_status();
                    ptd = true;
                }
            }
            else {
                ++tmp;
                last = 0;
            }
            ++p1;
            if (p1 > nt) p1 -= nt;
        }
        if (!ptd) {
            cout << "Case " << kase << ": still live after " << nf << " transitions\n";
            print_status();
        }
    }
    return 0;
}