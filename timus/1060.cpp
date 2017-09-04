#include <iostream>
#include <cstring>
#include <string>
#include <map>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define IS_NOT(a) (a)=!(a)
using namespace std;

bool board[4][4], tmp[4][4];
const int c[2] = { 4080, 255 };  // c[0] = (111111110000)_2, c[1] = (11111111)_2
map<int, int> d[4];

int cnt(int n) {
    int res = 0;
    while (n > 0) {
        if (n & 1) ++res;
        n >>= 1;
    }
    return res;
}

void flip_piece(int i, int j) {
    IS_NOT(tmp[i][j]);
    if (i > 0) IS_NOT(tmp[i - 1][j]);
    if (i < 3) IS_NOT(tmp[i + 1][j]);
    if (j > 0) IS_NOT(tmp[i][j - 1]);
    if (j < 3) IS_NOT(tmp[i][j + 1]);
}

void flip(int num, int down) {  // num is a 12-digit binary number; down = 0 or 1
    memcpy(tmp, board, sizeof(board));
    for (int i = 0 + down; i < 3 + down; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (num & 1)
                flip_piece(i, j);
            num >>= 1;
        }
    }
    return;
}

int is_win(int down) {
    int cnt = 0;
    for (int i = 0 + 2*down; i < 2 + 2*down; ++i)
        for (int j = 0; j < 4; ++j)
            if (tmp[i][j])
                ++cnt;
    if (cnt == 8) return 1;
    else if (cnt == 0) return 0;
    else return -1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string s;
    for (int i = 0; i < 4; ++i) {
        cin >> s;
        for (int j = 0; j < 4; ++j)
            board[i][j] = s[j] == 'b' ? 1 : 0;
    }
    int state;
    for (int i = 0; i < (1 << 12); ++i) {
        flip(i, 0);
        if ((state = is_win(0)) != -1)
            d[state][(i&c[0]) >> 4] = i;
    }
    for (int i = 0; i < (1 << 12); ++i) {
        flip(i, 1);
        if ((state = is_win(1)) != -1 && d[state].count(i&c[1]) != 0)
            d[state + 2][i&c[1]] = i;
    }
    if (d[2].empty() && d[3].empty()) {
        cout << "Impossible\n";
        return 0;
    }
    int mi = 16;
    for (int id = 2; id < 4; ++id)
        for (map<int, int>::iterator it = d[id].begin(); it != d[id].end(); ++it)
            mi = MIN(mi, cnt(it->second) + cnt(d[id - 2][it->first]) - cnt(it->first));
    cout << mi << endl;
    return 0;
}