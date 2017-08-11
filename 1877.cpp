#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int a, b;
	//cin >> a, b;
	scanf("%d%d", &a, &b);
	cout << (a % 2 == 0 || b % 2 != 0 ? "yes" : "no") << endl;
	return 0;
}
