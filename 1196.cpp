#include <iostream>
#include <string>
#include <set>
using namespace std;

set<long long> prof, stu;

int main() {
	ios::sync_with_stdio(false);
	int n, res = 0;
	long long s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		prof.insert(s);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (prof.count(s)) res++;
	}
	cout << res << endl;
 	return 0;
}
