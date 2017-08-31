#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
#include <stack>

using namespace std;

map<string, int> dict, vector_ids;
map<int, int> values[1000];

int str2int(const string s) {
	int res;
	sscanf(s.c_str(), "%d", &res);
	return res;
}

// for a[b], s_const = "b" for left and "a[b]" for right
bool islegal(const string s_const, int & value) {
	int p, q;
	string var, s = s_const;
	stack<string> name;
	while ((p = s.find('[')) != string::npos && (q = s.rfind(']')) != string::npos) {
		name.push(s.substr(0, p));
		s = s.substr(p + 1, q - p - 1);
	}
	value = str2int(s);
	while (!name.empty()) {
		var = name.top();
		map<int, int> &ref = values[vector_ids[var]];
		map<int, int>::iterator it = ref.find(value);
		if (value >= dict[var] || it == ref.end())
			return false;
		value = it->second;
		name.pop();
	}
	return true;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string line;
	bool end, legal = true;
	int bug = 0, vector_id = 0;
	while (getline(cin, line)) {
		if (line[0] == '.')
			if (!end) {
				cout << (legal ? 0 : bug) << endl;
				dict.clear();
				vector_ids.clear();
				for (int i = 0; i < 1000; i++)
					values[i].clear();
				end = legal = true;
				bug = 0;
				vector_id = 0;
				continue;
			}
			else
				break;
		else if (!legal)
			continue;
		end = false;
		bug++;
		stringstream ss(line);
		int pos = line.find('=');
		if (pos == string::npos) { // declaration
			int p = line.find('['), q = line.find(']');
			string tmp_var = line.substr(0, p);
			int tmp_id = str2int(line.substr(p + 1, q - p - 1));
			dict[tmp_var] = tmp_id;
			vector_ids[tmp_var] = vector_id;
			vector_id++;
		}
		else {
			string left = line.substr(0, pos), right = line.substr(pos + 1, line.size() - pos - 1);
			int p = left.find('[');
			string left_var = left.substr(0, p), left_val = left.substr(p + 1, left.size() - p - 2);
			int key, value;
			if (!islegal(left_val, key) || !islegal(right, value)) {
				legal = false;
				continue;
			}
			if (dict.find(left_var) == dict.end() || key >= dict[left_var]) {
				legal = false;
				continue;
			}
			values[vector_ids[left_var]][key] = value;
		}
	}
	return 0;
}