//¶¯Ì¬¹æ»®
#include <iostream>
#include <cstring>
using namespace std;

long long a[82];

void f() {
	long long b[82];
	memcpy(b, a, sizeof(a));
	for (int i = 0; i < 82 && a[i]; i++)
		for (int j = 1; j <= 9 && i + j < 82; j++)
			b[i + j] += a[i];
	memcpy(a, b, sizeof(a));
}

int main() {
	//freopen("in.txt", "r", stdin);
	int s;
	long long res = 0;
	cin >> s;
	for (int i = 0; i <= 9; i++) a[i] = 1;
	for (int i = 1; i <= 8; i++) f();
	++a[1];
	cout << a[s] << endl;
	return 0;
}