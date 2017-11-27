/*
ID: wanying1
PROG: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n, a, b, milk = 0, idle = 0;
    fin >> n;
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; ++i)
		fin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	if (n > 0) {
		a = v[0].first;
		b = v[0].second;
		milk = b - a;
	}
	for (int i = 1; i < n; ++i) {
		if (v[i].first <= b) {
			b = max(b, v[i].second);
			milk = max(milk, b - a);
		}
		else {
			idle = max(idle, v[i].first - b);
			a = v[i].first;
			b = v[i].second;
			milk = max(milk, b - a);
		}
	}
	fout << milk << " " << idle << endl;
    return 0;
}