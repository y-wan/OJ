#include <iostream>
#include <string>
using namespace std;

int arr[105];

int main() {
	string s;
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++)
		arr[i] = s[i] - 'a';
	for (int i = l - 1; i > 0; i--) {
		arr[i] -= arr[i - 1];
		while (arr[i] < 0) arr[i] += 26;
	}
	arr[0] -= 5;
	if (arr[0] < 0) arr[0] += 26;
	for (int i = 0; i < l; i++) cout << char(arr[i] + 'a');
	cout << endl;
	return 0;
}
