#include <iostream>
#include <vector>

using namespace std;

bool ducci(vector<int> &seq) {
	int tmp = seq[0], n = seq.size();
	bool allzero = true;
	for (int i = 0; i < n - 1; i++)
		seq[i] -= seq[i + 1];
	seq[n - 1] -= tmp;
	for (int i = 0; i < n; i++) {
		seq[i] = seq[i] > 0 ? seq[i] : -seq[i];
		if (seq[i])
			allzero = false;
	}
	return allzero;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, n;
	vector<int> seq;
	cin >> T;
	for (int t = 0; t < T; t++) {
		bool allzero = true;
		int step = 0;
		cin >> n;
		seq.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> seq[i];
			if (seq[i])
				allzero = false;
		}
		while (!allzero && step < 1000) {
			allzero = ducci(seq);
			step++;
		}
		cout << (allzero ? "ZERO" : "LOOP") << endl;
	}
	return 0;
}