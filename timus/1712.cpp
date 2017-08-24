#include <iostream>
#include <set>
#include <string>
using namespace std;

set<pair<int, int> > dict;
pair<int, int> win[4];

pair<int, int> rot(pair<int, int> win) {
	pair<int, int> p = win;
	p.first = 2 * p.first - 3;
	p.second = 2 * p.second - 3;
	int tmp = p.first;
	p.first = p.second;
	p.second = -tmp;
	p.first = (p.first + 3) / 2;
	p.second = (p.second + 3) / 2;
	return p;
}

int main() {
	string s, res = "", c[4];
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 4; j++)
			if (s[j] == 'X')
				dict.insert(pair<int, int>(i, j));
	}
	for (int i = 0; i < 4; i++)
		cin >> c[i];
	for (int i = 0; i < 4; i++) {
		set<pair<int, int> >::iterator it = dict.begin();
		for (int j = 0; j < 4; j++) {
			res += c[it->first][it->second];
			win[j] = rot(*it);
			it++;
		}
		dict.clear();
		for (int j = 0; j < 4; j++)
			dict.insert(pair<int, int>(win[j].first, win[j].second));
	}
	cout << res << endl;
	return 0;
}
