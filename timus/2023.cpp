#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	int a, pos = 0, res = 0;
	char c, name[100];
	cin >> a;
	string s[3] = { "AOPR", "BMS", "DGJKTW" };
	for (int i = 0; i < a; i++) {
		cin >> name;
		c = name[0];
		for (int j = 0; j < 3; j++)
			if (strchr(s[j].c_str(), c)) {
				res += (pos > j ? pos - j : j - pos);
				pos = j;
				break;
			}
	}
	cout << res << endl;
	return 0;
}
