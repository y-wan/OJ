#include <iostream>
#include <map>

using namespace std;

map<int, int> d;

void process(int n) {
    int i = 2;
    while (n > 1) {
        while (n % i == 0) {
            n /= i;
            ++d[i];
        }
        ++i;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, res = 1;
    for (int i = 0; i < 10; ++i) {
        cin >> n;
        process(n);
    }
    for (map<int, int>::iterator it = d.begin(); it != d.end(); ++it)
        res *= (it->second + 1) % 10;
    cout << res % 10 << endl;
    return 0;
}