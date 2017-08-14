#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, int> id;
vector<string> a[4];

int main() {
	//ios_base::sync_with_stdio(false);
	int n, end = -1, p = 0, sum = 0;
	id["Slytherin"] = 0;
	id["Hufflepuff"] = 1;
	id["Gryffindor"] = 2;
	id["Ravenclaw"] = 3;
	string school[4] = { "Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw" };	
	cin >> n;
	string name, s;
	for (int i = 0; i < n; i++) {
		getline(cin, name);
		getline(cin, name);
		cin >> s;
		a[id[s]].push_back(name);
	}
	for (int i = 0; i < 4; i++) {
		if (i > 0) cout << endl;
		cout << school[i] << ":" << endl;
		int len = a[i].size();
		for (int j = 0; j < len; j++) cout << a[i][j] << endl;
	}
	return 0;
}
