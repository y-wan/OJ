#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> a[5000];

int main() {
    int n;
    bool first = false;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    for (int i = 1; i < n; ++i)
        if (!first && a[i].second < a[i - 1].second) first = true;
        else if (first && a[i].second >= a[i - 1].first) first = false;
    if (!first) cout << a[n - 1].second << endl;
    else cout << a[n - 1].first << endl;
    return 0;
}

