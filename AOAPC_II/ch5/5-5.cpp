#include <iostream>
#include <vector>
#include <string>
#include <set>
//#include <ctime>
using namespace std;

set<string> dict, ans;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n = 0;
	string buf;
	while (cin >> buf) {
		dict.insert(buf);
		n++;
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
		string cpd = *it;
		int len = cpd.size();
		for (int p = 1; p < len; p++) {
			if (dict.count(cpd.substr(0, p)) && dict.count(cpd.substr(p)) && !ans.count(cpd)) {
				cout << cpd << endl;
				ans.insert(cpd);
				break;
			}
		}
	}
	//cout << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}