/*
ID: wanying1
PROG: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, int> dict;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n, tot, num, div, res;
	string name;
    fin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		fin >> v[i];
		dict[v[i]] = 0;
	}
	for (int i = 0; i < n; ++i) {
		fin >> name >> tot >> num;
		if (num == 0) continue;
		div = tot / num;
		res = tot % num;
		dict[name] += res - tot;
		for (int j = 0; j < num; ++j) {
			fin >> name;
			dict[name] += div;
		}
	}
	for (int i = 0; i < n; ++i)
		fout << v[i] << " " << dict[v[i]] << endl;
    return 0;
}