#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char,int> dict;

void init() {
	for (char c = 'a'; c <= 'z'; c++)
		dict[c] = (c - 'a') % 3 + 1;
	dict['.'] = 1;
	dict[','] = 2;
	dict['!'] = 3;
	dict[' '] = 1;
}

int main() {
	init();
	string s;
	getline(cin, s);
	int len = s.size(), sum = 0;
	for (int i = 0; i < len; i++)
		sum += dict[s[i]];
	cout << sum << endl;
	return 0;
}
