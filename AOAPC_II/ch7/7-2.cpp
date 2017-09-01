#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#define ABS(a) ((a)>0?(a):(-(a)))

using namespace std;

set<pair<int, int> > blocked, visited;
vector<char> d;
int cnt_print;

void print_d() {
    for (int j = 0; d[j] != '\0'; ++j) cout << d[j];
    cout << '\n';
}

bool is_blocked(const int x, const int y, const int d, char direction) {
    switch (direction) {
    case 'n':
        for (int i = 0; i <= d; ++i) if (blocked.count(make_pair(x, y + i)) != 0) return true;
        break;
    case 's':
        for (int i = 0; i <= d; ++i) if (blocked.count(make_pair(x, y - i)) != 0) return true;
        break;
    case 'e':
        for (int i = 0; i <= d; ++i) if (blocked.count(make_pair(x + i, y)) != 0) return true;
        break;
    case 'w':
        for (int i = 0; i <= d; ++i) if (blocked.count(make_pair(x - i, y)) != 0) return true;
        break;
    default:
        break;
    }
    return false;
}

bool is_visited(const int x, const int y) {
    if (visited.count(make_pair(x, y)) != 0) return true;
    return false;
}

void bf(const int x, const int y, const int cur_len, const int ma) {
    if ((x != 0 || y != 0) && is_visited(x, y) || x == 0 && y == 0 && cur_len != ma + 1 && cur_len != 1) return;
    if (cur_len == ma + 1) {
        if (x == 0 && y == 0) {
            print_d();
            ++cnt_print;
        }
        return;
    }
    if ((ma + cur_len)*(ma - cur_len + 1) / 2 < ABS(x) + ABS(y)) return;
    visited.insert(make_pair(x, y));
    if (cur_len == 1) {
        if (!is_blocked(x, y, cur_len, 'e')) {
            d[cur_len - 1] = 'e';
            bf(x + cur_len, y, cur_len + 1, ma);
            d[cur_len - 1] = '\0';
        }
        if (!is_blocked(x, y, cur_len, 'n')) {
            d[cur_len - 1] = 'n';
            bf(x, y + cur_len, cur_len + 1, ma);
            d[cur_len - 1] = '\0';
        }
        if (!is_blocked(x, y, cur_len, 's')) {
            d[cur_len - 1] = 's';
            bf(x, y - cur_len, cur_len + 1, ma);
            d[cur_len - 1] = '\0';
        }
        if (!is_blocked(x, y, cur_len, 'w')) {
            d[cur_len - 1] = 'w';
            bf(x - cur_len, y, cur_len + 1, ma);
            d[cur_len - 1] = '\0';
        }
        
    }
    else {
        switch (d[cur_len - 2]) {
        case 'e':
            if (!is_blocked(x, y, cur_len, 'n')) {
                d[cur_len - 1] = 'n';
                bf(x, y + cur_len, cur_len + 1, ma);
                d[cur_len - 1] = '\0';
            }
            if (!is_blocked(x, y, cur_len, 's')) {
                d[cur_len - 1] = 's';
                bf(x, y - cur_len, cur_len + 1, ma);
                d[cur_len - 1] = '\0';
            }
            break;
        case 'n': case's':
            if (!is_blocked(x, y, cur_len, 'e')) {
                d[cur_len - 1] = 'e';
                bf(x + cur_len, y, cur_len + 1, ma);
                d[cur_len - 1] = '\0';
            }
            if (!is_blocked(x, y, cur_len, 'w')) {
                d[cur_len - 1] = 'w';
                bf(x - cur_len, y, cur_len + 1, ma);
                d[cur_len - 1] = '\0';
            }
            break;
         case 'w' :
            if (!is_blocked(x, y, cur_len, 'n')) {
                d[cur_len - 1] = 'n';
                bf(x, y + cur_len, cur_len + 1, ma);
                d[cur_len - 1] = '\0';
            }
            if (!is_blocked(x, y, cur_len, 's')) {
                d[cur_len - 1] = 's';
                bf(x, y - cur_len, cur_len + 1, ma);
                d[cur_len - 1] = '\0';
            }
            break;
        default: break;
        }
    }
    visited.erase(make_pair(x, y));
}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // _DEBUG
    ios::sync_with_stdio(false);
    int cities, n, block_num, tx, ty;
    d.resize(20);
    cin >> cities;
    while (cities-- > 0) {
        blocked.clear();
        visited.clear();
        for (int i = 0; i < 20; ++i) d[i] = '\0';
        cnt_print = 0;
        cin >> n >> block_num;
        while (block_num-- > 0) {
            cin >> tx >> ty;
            blocked.insert(make_pair(tx, ty));
        }
        bf(0, 0, 1, n);
        cout << "Found " << cnt_print << " golygon(s).\n\n";
    }
    return 0;
}