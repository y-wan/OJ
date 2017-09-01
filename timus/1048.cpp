#include <cstring>
#include <cstdio>

using namespace std;

int a[1000001];

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // _DEBUG
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        a[i] = x + y;
    }
    for (int i = n; i > 0; --i) {
        if (a[i] >= 10) {
            a[i - 1] += a[i] / 10;
            a[i] %= 10;
        }
    }
    if (a[0] > 0) printf("%d", a[0]);
    for (int i = 1; i <= n; ++i) printf("%d", a[i]);
    printf("\n");
    return 0;
}