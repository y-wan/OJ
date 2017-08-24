//二叉树_通过中序和后序遍历构建树
#include <iostream>

using namespace std;

typedef struct Node {
	int val = 0;
	Node *left = NULL;
	Node *right = NULL;
} node, *pnode;

int a[3000];

int *arr_lower_bound(int *begin, int *end, int val) {
	int *p = begin;
	for (; p != end; p++)
		if (*p >= val) break;
	return p;
}

void build_tree(pnode root, int *begin, int *end) {
	int *mid = arr_lower_bound(begin, end, root->val), *p1 = mid, *p2 = --end;
	--p1, --p2;
	if (mid != begin) {
		root->left = new node();
		root->left->val = *p1;
		build_tree(root->left, begin, mid);
	}
	if (mid != end) {
		root->right = new node();
		root->right->val = *p2;
		build_tree(root->right, mid, end);
	}
}

void print_tree(pnode root) {
	if (root->right != NULL) print_tree(root->right);
	if (root->left != NULL) print_tree(root->left);
	cout << root->val << endl;
}

int main() {
	//ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	pnode root = new node();
	root->val = a[n - 1];
	build_tree(root, a, a + n);
	print_tree(root);
	return 0;
}