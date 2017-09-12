#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, l, r, a;
    scanf("%d", &n);
    vector<pair<int, int> > d(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        d[i].first = a;
        d[i].second = i + 1;
    }
    sort(d.begin(), d.end());
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &l, &r, &a);
        auto itt = lower_bound(d.begin(), d.end(), make_pair(a, l));
        (itt != d.end() && itt->first == a && itt->second <= r) ? putchar('1') : putchar('0');
    }
    return 0;
}