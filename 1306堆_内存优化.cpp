//¶Ñ¡¢ÄÚ´æÓÅ»¯
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int tmp;
	cin >> n;
	vector<int> a(n / 2 + 1, 0);
	for (int i = 0; i < n / 2 + 1; i++) cin >> a[i];
	make_heap(a.begin(), a.end());
	if (n % 2 == 0) {
		for (int i = 1; i <= n / 2 - 1; ++i) {
			cin >> tmp;
			if (a.front() > tmp) {
				pop_heap(a.begin(), a.end());
				a.back() = tmp;
				push_heap(a.begin(), a.end());
			}
		}
		tmp = a.front();
		pop_heap(a.begin(), a.end());
		printf("%.1f\n", tmp + (a.front() - tmp) / 2.0);
	}
	else {
		for (int i = 1; i <= n / 2; ++i) {
			cin >> tmp;
			if (a.front() > tmp) {
				pop_heap(a.begin(), a.end());
				a.back() = tmp;
				push_heap(a.begin(), a.end());
			}
		}
		printf("%.1f\n", double(a.front()));
	}
	return 0;
}