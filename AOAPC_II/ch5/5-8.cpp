#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;

struct CMP {
	bool operator () (const pair<string, string> a, const pair<string, string> b) {
		if (a.second != b.second)
			return a.second < b.second;
		else
			return a.first < b.first;
	}
} cmp;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string line;
	vector<pair<string, string> > shelf, ret;
	map<string, string> book;
	bool end = false;
	while (getline(cin, line)) {
		stringstream ss(line);
		if (line[0] == '"') {
			int p = line.find('"', 1);
			string title = line.substr(1, p - 1), author = line.substr(p + 5);
			book[title] = author;
			pair<string, string> tmp = make_pair(title, author);
			vector<pair<string, string> >::iterator it = lower_bound(shelf.begin(), shelf.end(), tmp, cmp);
			shelf.insert(it, tmp);
		}
		else if (line[0] == 'E') {
			if (!end)
				end = true;
			else
				break;
		}
		else if (line[0] == 'B') {
			string title = line.substr(8, line.size() - 9);
			vector<pair<string, string> >::iterator it = shelf.begin();
			while (it->first != title)
				it++;
			shelf.erase(it);
		}
		else if (line[0] == 'R') {
			string title = line.substr(8, line.size() - 9);
			pair<string, string> book_pair = make_pair(title, book[title]);
			vector<pair<string, string> >::iterator it = lower_bound(ret.begin(), ret.end(), book_pair, cmp);
			ret.insert(it, book_pair);
		}
		else if (line[0] == 'S') {
			for (vector<pair<string, string> >::iterator it = ret.begin(); it != ret.end(); it++) {
				vector<pair<string, string> >::iterator pos = lower_bound(shelf.begin(), shelf.end(), *it, cmp);
				if (pos != shelf.begin())
					cout << "Put \"" << it->first << "\" after \"" << (pos - 1)->first << "\"" << endl;
				else
					cout << "Put \"" << it->first << "\" first" << endl;
				shelf.insert(pos, *it);
			}
			ret.clear();
			cout << "END" << endl;
		}
		else {
			cout << "Something is wrong." << endl;
		}
	}
	return 0;
}