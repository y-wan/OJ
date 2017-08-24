#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<int, int>dict;

int main() {
	int n, m, num;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dict[num] = 0;
	for (int i = 0; i < m; i++) {
		cin >> num;
		dict[num]++;
	}
	for (int i = 1; i <= n; i++)
		printf("%.2f%%\n", (double)dict[i] * 100 / m);
	return 0;
}
