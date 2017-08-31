#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val('\0'), left(NULL), right(NULL) {}
};

TreeNode* createTree(TreeNode* root, const string& s, const string& t) {
    // !s.empty()
    root->val = s[0];
    if (s.size() == 1) return root;
    int a = t.find(s[0]), b = s.size() - 1 - a;
    if (a != 0) {
        root->left = new TreeNode();
        createTree(root->left, s.substr(1, a), t.substr(0, a));
    }
    if (b != 0) {
        root->right = new TreeNode();
        createTree(root->right, s.substr(1 + a, b), t.substr(a + 1, b));
    }
    return root;
}

void printTree(TreeNode* root) {
    if (!root) return;
    if (root->left) printTree(root->left);
    if (root->right) printTree(root->right);
    cout << root->val;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    string s, t;
    while (cin >> s >> t) {
        TreeNode* res = new TreeNode();
        createTree(res, s, t);
        printTree(res);
        cout << endl;
    }
    return 0;
}