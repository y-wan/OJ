#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	int p1 = s.find('{'), p2 = s.find('('), p3 = s.find('['), q1 = s.find('}'), q2 = s.find(')'), q3 = s.find(']');
	s[p1 + 1] = toupper(s[p1 + 1]), s[p2 + 1] = tolower(s[p2 + 1]), s[p3 + 1] = tolower(s[p3 + 1]);
	int m = -1;
	int mi = p1 < p2 ? p1 : p2;
	mi = mi < p3 ? mi : p3;
	cout << s.substr(1, mi);
	while (!s.empty()) {
		//cout << s.substr(m + 1, mi - m - 1);
		cout << s.substr(p1 + 1, q1 - p1 - 1) << ' ' << s.substr(p2 + 1, q2 - p2 - 1) << ' ' << s.substr(p3 + 1, q3 - p3 - 1);
		m = q1 > q2 ? q1 : q2;
		m = m > q3 ? m : q3;
		s = s.substr(m + 1, s.size() - m - 1);
		p1 = s.find('{'), p2 = s.find('('), p3 = s.find('['), q1 = s.find('}'), q2 = s.find(')'), q3 = s.find(']');
		mi = p1 < p2 ? p1 : p2;
		mi = mi < p3 ? mi : p3;
		cout << s.substr(0, mi);
	}
	cout << endl;
	return 0;
}
