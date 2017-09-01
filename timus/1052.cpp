#include <iostream>
#include <map>
#define ABS(a) ((a)>0?(a):(-(a)))

using namespace std;

int a[200][2];
map<pair<int, int>, int> d;

int gcd(int m, int n) {
    int t;
    while (n > 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

void add_pair(int i, int j) {
    if (a[i][0] == a[j][0])
        ++d[make_pair(0, 1)];
    else if (a[i][1] == a[j][1])
        ++d[make_pair(1, 0)];
    else {
        int x = a[i][1] - a[j][1], y = a[j][0] - a[i][0], g;
        if (x < 0) {
            x = -x;
            y = -y;
        }
        g = gcd(x, ABS(y));
        ++d[make_pair(x / g, y / g)];
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];
    int m = 0;
    for (int i = 0; i < n; ++i) {
        d.clear();
        for (int j = 0; j < n; ++j)
            if (i != j) add_pair(i, j);
        for (map<pair<int, int>, int>::iterator it = d.begin(); it != d.end(); ++it)
            m = m > it->second ? m : it->second;
    }
    cout << m + 1 << endl;
    return 0;
}