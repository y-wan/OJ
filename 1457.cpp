#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n, tmp, sum = 0;
	double res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
	}
	printf("%.6f\n", double(sum) / n);	
	return 0;
}
