#include <iostream>
#define ABS(a) ((a)>0?(a):(-(a)))

using namespace std;

int level[15000], cntx[32001];
int bucket[129];

int cnt_level(int a) {
    int res = 0, ma_b = a / 250;
    for (int i = 0; i < ma_b; ++i)
        res += bucket[i];
    for (int i = a / 250 * 250; i <= a; ++i)
        res += cntx[i];
    return res;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        ++level[cnt_level(a)];
        ++cntx[a];
        ++bucket[a / 250];
    }
    for (int i = 0; i < n; ++i) cout << level[i] << endl;
    return 0;
}