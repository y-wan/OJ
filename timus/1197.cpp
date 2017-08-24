#include <iostream>
#include <string>
using namespace std;

int board[8][8] = {
	{ 2,3,4,4,4,4,3,2 },
	{ 3,4,6,6,6,6,4,3 },
	{ 4,6,8,8,8,8,6,4 },
	{ 4,6,8,8,8,8,6,4 },
	{ 4,6,8,8,8,8,6,4 },
	{ 4,6,8,8,8,8,6,4 },
	{ 3,4,6,6,6,6,4,3 },
	{ 2,3,4,4,4,4,3,2 } };

int main() {
	int a;
	string s;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> s;
		cout << board[s[0] - 'a'][s[1] - '1'] << endl;
	}
	return 0;
}
