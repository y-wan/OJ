#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string s[4] = { "11","01","60","80" };
	cin >> n;
	if (n <= 4) {
		for (int i = 0; i < n - 1; i++)
			cout << s[i] << " ";
		cout << s[n - 1] << endl;
	}
	else
		cout << "Glupenky Pierre" << endl;
	return 0;
}
