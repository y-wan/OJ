/*
ID: wanying1
PROG: ariprog
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 125001
using namespace std;

bool isBisq[MAX];

int main() {
	ofstream fout("ariprog.out");
	ifstream fin("ariprog.in");
	int n, m, numBisq = 0;
	fin >> n >> m;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (!isBisq[i*i+j*j]) {
				++numBisq;
				isBisq[i*i+j*j] = true;
			}			
		}
	}
	vector<int> v(numBisq);
    vector<pair<int, int> > ans;
	int id = 0;
	for (int i = 0; i < MAX; ++i) {
		if (isBisq[i]) {
			v[id] = i;
			++id;
		}
	}
    for (int i = 0; i < numBisq; ++i) {
        for (int j = i + 1; j < numBisq; ++j) {
            int d = v[j] - v[i];
            bool isAns = true;
            for (int k = v[j]; k <= v[j] + (n - 2)*d; k += d) {
                if (k > v[numBisq - 1] || !isBisq[k]) {
                    isAns = false;
                    break;
                }
            }
            if (isAns) ans.push_back(make_pair(d, v[i]));
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        fout << "NONE" << endl;
        return 0;
    }
    for (vector<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); ++it)
        fout << it->second << ' ' << it->first << endl;
	return 0;
}
