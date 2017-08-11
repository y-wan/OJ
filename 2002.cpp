#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, pair<string, bool> > u;

int main() {
	int n;
	cin >> n;
	string cmd, s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> cmd >> s1;
		switch (cmd[4]) {
		case 's':
			cin >> s2;
			if (!u.count(s1)) {
				cout << "success: new user added" << endl;
				u[s1] = pair<string, bool>(s2, false);
			}
			else cout << "fail: user already exists" << endl;
			break;
		case 'n':
			cin >> s2; 
			if (!u.count(s1))
				cout << "fail: no such user" << endl;
			else if (u[s1].first != s2)
				cout << "fail: incorrect password" << endl;
			else if (u[s1].second == true)
				cout << "fail: already logged in" << endl;
			else {
				u[s1].second = true;
				cout << "success: user logged in" << endl;
			}
			break;
		case 'u':
			if (!u.count(s1))
				cout << "fail: no such user" << endl;
			else if (u[s1].second == false)
				cout << "fail: already logged out" << endl;
			else {
				u[s1].second = false;
				cout << "success: user logged out" << endl;
			}
			break;
		default:
			break;
		}
	}
 	return 0;
}
