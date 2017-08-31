#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, l;
    string s;
    cin >> n;
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        l = s.size();
        stack<int> d;
        bool y = true;
        for (int j = 0; j < l && y; ++j) {
            switch (s[j])
            {
            case '(': case '[': d.push(s[j]); break;
            case ')':
                if (d.empty() || d.top() != '(') y = false;
                else d.pop();
                break;
            case ']':
                if (d.empty() || d.top() != '[') y = false;
                else d.pop();
                break;
            default:
                break;
            }
        }
        cout << (y && d.empty() ? "Yes\n" : "No\n");
    }
    return 0;
}