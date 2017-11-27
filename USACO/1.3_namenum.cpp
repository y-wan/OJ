/*
ID: wanying1
PROG: namenum
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<char, char> dict;

bool isValid(const string &n, const string &name) {
	int len = n.length();
	if (len != name.length()) return false;
	for (int i = 0; i < len; ++i)
		if (dict[name[i]] != n[i]) return false;
	return true;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
	ifstream fdict ("dict.txt");
	bool hasValid = false;
	dict['A'] = dict['B'] = dict['C'] = '2';
	dict['D'] = dict['E'] = dict['F'] = '3';
	dict['G'] = dict['H'] = dict['I'] = '4';
	dict['J'] = dict['K'] = dict['L'] = '5';
	dict['M'] = dict['N'] = dict['O'] = '6';
	dict['P'] = dict['R'] = dict['S'] = '7';
	dict['T'] = dict['U'] = dict['V'] = '8';
	dict['W'] = dict['X'] = dict['Y'] = '9';
    string n, name;
    fin >> n;
	while (fdict >> name) {
		if (isValid(n, name)) {
			fout << name << endl;
			hasValid = true;
		}
	}
	if (!hasValid) fout << "NONE" << endl;
    return 0;
}