#include <iostream>
#include <string>
using namespace std;

int main() {	
	string s;
	cin >> s;
	int n = 0, len = s.size();
	for (int i = 0; i < len; i++) n += s[i] - '0';
	if (n % 3) cout << 1 << endl << n % 3 << endl;
	else cout << 2 << endl;
	return 0;
}
