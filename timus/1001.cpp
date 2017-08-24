#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

stack<double> s;

int main() {
	double tmp;
	while (scanf("%lf", &tmp) == 1)
		s.push(tmp);
	while (!s.empty()) {
		printf("%.4f\n", sqrt(s.top()));
		s.pop();
	}
	return 0;
}
