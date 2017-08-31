#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

stack<string> cards[52];
int remain = 52;

int left(int i, int d) {
    int cnt = 0, p = i - 1;
    while (p >= 0) {
        if (!cards[p].empty()) ++cnt;
        if (cnt == d) break;
        --p;
    }
    return cnt == d ? p : -1;
}

bool move() {
    int p;
    for (int i = 1; i < 52; ++i) {
        if (!cards[i].empty()) {
            p = left(i, 3);
            if (p >= 0 && !cards[p].empty() && (cards[i].top()[0] == cards[p].top()[0] || cards[i].top()[1] == cards[p].top()[1])) {
                cards[p].push(cards[i].top());
                cards[i].pop();
                if (cards[i].empty()) --remain;
                return true;
            }
            p = left(i, 1);
            if (p >= 0 && !cards[p].empty() && (cards[i].top()[0] == cards[p].top()[0] || cards[i].top()[1] == cards[p].top()[1])) {
                cards[p].push(cards[i].top());
                cards[i].pop();
                if (cards[i].empty()) --remain;
                return true;
            }
        }
    }
    return false;
}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // _DEBUG
    string s;
    while (cin >> s && s[0] != '#') {
        for (int i = 0; i < 52; ++i)
            while (!cards[i].empty())
                cards[i].pop();
        remain = 52;
        cards[0].push(s);
        for (int i = 1; i < 52; ++i) {
            cin >> s;
            cards[i].push(s);
        }
        while (move());
        if (remain > 1) {
            cout << remain << " piles remaining:";
            for (int i = 0; i < 52; ++i)
                if (!cards[i].empty())
                    cout << ' ' << cards[i].size();
            cout << endl;
        }
        else cout << "1 pile remaining: 52\n";
    }
    return 0;
}