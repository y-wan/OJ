#include <iostream>
#include <queue>

using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	while (cin >> n && n) {
		queue<int> cards;
		for (int i = 0; i < n; i++)
			cards.push(i + 1);
		if (n == 1) {
			cout << "Discarded cards:" << endl << "Remaining card: " << cards.front() << endl;
			continue;
		}
		cout << "Discarded cards: " << cards.front();
		cards.pop();
		cards.push(cards.front());
		cards.pop();
		while (cards.size() > 1) {
			cout << ", " << cards.front();
			cards.pop();
			cards.push(cards.front());
			cards.pop();
		}
		cout << endl << "Remaining card: " << cards.front() << endl;
	}
	return 0;
}