/*
ID: wanying1
PROG: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> rotate(const vector<string> &v) {
	int n = v.size();
	vector<vector<char> > tmp(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			tmp[j][n-1-i] = v[i][j];
	vector<string> ret(n);
	for (int i = 0; i < n; ++i) ret[i] = string(tmp[i].begin(), tmp[i].end());
	return ret;
}

vector<string> reflect(const vector<string> &v) {
	int n = v.size();
	vector<vector<char> > tmp(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			tmp[i][n-1-j] = v[i][j];
	vector<string> ret(n);
	for (int i = 0; i < n; ++i) ret[i] = string(tmp[i].begin(), tmp[i].end());
	return ret;
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin >> n;
	vector<string> v(n), w(n);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
	for (int i = 0; i < n; ++i)
		fin >> w[i];
	vector<string> v1 = rotate(v), v2 = rotate(v1), v3 = rotate(v2),
		v4 = reflect(v), v5_1 = rotate(v4), v5_2 = rotate(v5_1), v5_3 = rotate(v5_2);
	if (v1 == w) fout << "1" << endl;
	else if (v2 == w) fout << "2" << endl;
	else if (v3 == w) fout << "3" << endl;
	else if (v4 == w) fout << "4" << endl;
	else if (v5_1 == w || v5_2 == w ||v5_3 == w) fout << "5" << endl;
	else if (v == w) fout << "6" << endl;	
	else fout << "7" << endl;
    return 0;
}