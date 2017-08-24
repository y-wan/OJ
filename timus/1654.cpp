#include <iostream>
#include <string>
#include <queue>
using namespace std;

deque<char> st;

int main() {
	string s;
	cin >> s;
	int len = s.size(), old_id = 0;
	for (int i = 0; i < len; i++) {
		if (!st.empty() && st.back() == s[i])
			st.pop_back();
		else
			st.push_back(s[i]);
	}
	while (!st.empty()) {
		cout << st.front();
		st.pop_front();
	}
	cout << endl;
 	return 0;
}
