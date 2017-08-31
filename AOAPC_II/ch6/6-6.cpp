#include <iostream>
#include <string>
#include <map>

using namespace std;

int res = 0;
map<long long, long long> d;

struct TreeNode {
    long long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(long long n) : val(n), left(NULL), right(NULL) {}
};

long long to_long_long(string s) {
    long long res = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

int find_next_comma(string s) {
    int n = s.size(), cnt_left = 0;
    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
        case '[': ++cnt_left; break;
        case ']': --cnt_left; break;
        case ',': if (cnt_left == 1) return i; break;
        default: break;
        }
    }
    return -1;
}

int find_next_right_bracket(string s, int begin) {
    int n = s.size(), cnt_left = 0;
    for (int i = begin; i < n; ++i) {
        switch (s[i]) {
        case '[': ++cnt_left; break;
        case ']': if (cnt_left > 0) --cnt_left;
                  else return i;
                  break;
        default: break;
        }
    }
    return -1;
}

TreeNode* createTree(TreeNode* root, string s) {
    if (s.empty()) return root;
    int n = s.size(), a = find_next_comma(s);
    if (a != -1) {
        int b = find_next_right_bracket(s, a);
        root->left = new TreeNode();
        createTree(root->left, s.substr(1, a - 1));
        root->right = new TreeNode();
        createTree(root->right, s.substr(a + 1, b - a - 1));
    }
    else root->val = to_long_long(s);
    return root;
}

void cal(TreeNode* root, int dep) {
    if (!root) return;
    if (root->val) {
        ++d[root->val << dep];
        ++res;
    }
    if (!root->left) return;
    cal(root->left, dep + 1);
    cal(root->right, dep + 1);
}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // _DEBUG
    int kase;
    string s;
    cin >> kase;
    getline(cin, s);
    while (kase-- > 0) {
        getline(cin, s);
        TreeNode* root = new TreeNode();
        createTree(root, s);
        res = 0;
        d.clear();
        cal(root, 0);
        int m = 0;
        for (map<long long, long long>::iterator it = d.begin(); it != d.end(); ++it)
            m = m > it->second ? m : it->second;
        cout << res - m << endl;
    }
    return 0;
}