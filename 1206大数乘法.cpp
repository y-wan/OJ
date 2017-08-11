//大数乘法，稍微有点问题，不碍使用
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct BigInt {
	string val;  // reversed string
	BigInt operator * (BigInt& a) {
		BigInt res;
		int la = a.val.size(), lb = this->val.size(), *arr = (int*)calloc(la + lb, sizeof(int));
		for (int i = 0; i < la; i++)
			for (int j = 0; j < lb; j++)
				arr[i + j] += (a.val[i] - '0') * (this->val[j] - '0');
		for (int i = 0; i < la + lb - 1; i++) {
			while (arr[i] >= 10) {
				arr[i] -= 10;
				++arr[i + 1];
			}
		}
		int carry = 0;
		while (arr[la + lb - 1] >= 10) {
			arr[la + lb - 1] -= 10;
			++carry;
		}
		char *str = (char*)calloc(la + lb + 2, sizeof(char));
		for (int i = 0; i < la + lb; i++) str[i] = arr[i] + '0';
		str[la + lb] = '\0';
		string tmp(str);
		if (carry) tmp += carry + '0';
		res.val = tmp;
		free(arr);
		free(str);
		return res;
	}
};

int main() {
	int n;
	cin >> n;
	BigInt a, b;
	a.val = "0891", b.val = "55";
	for (int i = 3; i <= n; i++) a = a * b;
	string s = a.val;
	int l = s.size(), lead = -1;
	for (int i = l - 1; i >= 0; i--)
		if (s[i] != '0') {
			lead = i;
			break;
		}
	for (int i = lead; i >= 0; i--)
		cout << s[i];
	cout << endl;
	return 0;
}