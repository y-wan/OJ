/*
ID: wanying1
PROG: crypt1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>

using namespace std;

bool d[10];

bool isValid(int n) {
    while (n) {
        if (!d[n % 10]) return false;
        n /= 10;
    }
    return true;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int n, a, b, c, t1, t2, t3, ans = 0;
    fin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		fin >> v[i];
        d[v[i]] = true;
    }
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                a = 100*v[i] + 10*v[j] + v[k];
                if (a < 100) break;
                for (int l = 0; l < n; ++l) {
                    b = v[l];
                    if (b == 0) break;
                    for (int m = 0; m < n; ++m) {
                        c = v[m];
                        t1 = a*b, t2 = a*c, t3 = 10*t1 + t2;
                        if (t1 < 1000 && isValid(t1) && t2 < 1000 && isValid(t2) && t3 < 10000 && isValid(t3))
                            ++ans;
                    }
                }
            }
        }
	}
	fout << ans << endl;
    return 0;
}