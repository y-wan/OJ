/*
ID: wanying1
PROG: combo
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
#include <set>

using namespace std;

set<vector<int> > d;

void update(const vector<int> &v, int n) {
    for (int i = -2; i <= 2; ++i) {
		for (int j = -2; j <= 2; ++j) {
            for (int k = -2; k <= 2; ++k) {
                int tmp[3] = { (v[0]+n-i-1)%n+1, (v[1]+n-j-1)%n+1, (v[2]+n-k-1)%n+1 };
                d.insert(vector<int>(tmp, tmp + sizeof(tmp) / sizeof(int)));
            }
        }
    }
}

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
    int n;
    fin >> n;
	vector<int> v1(3), v2(3);
	for (int i = 0; i < 3; ++i)
		fin >> v1[i];
    for (int i = 0; i < 3; ++i)
		fin >> v2[i];
	update(v1, n);
    update(v2, n);
	fout << d.size() << endl;
    return 0;
}