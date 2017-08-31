#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> code[1000];
int wordlen[90], vsize[1000];

void countlen(const int numwords, const int numlines) {
	for (int i = 0; i < numwords; i++) {
		for (int j = 0; j < numlines; j++) {
			if (i >= vsize[j]) continue;
			wordlen[i] = wordlen[i] > code[j][i].size() ? wordlen[i] : code[j][i].size();
		}
		wordlen[i]++;  // room for space
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int numlines = 0, numwords = 0;
	string line, buf;
	while (getline(cin, line)) {
		stringstream ss(line);
		while (ss >> buf) {
			code[numlines].push_back(buf);
			vsize[numlines]++;
		}
		numlines++;
	}
	for (int i = 0; i < numlines; i++)
		numwords = numwords > vsize[i] ? numwords : vsize[i];
	countlen(numwords, numlines);
	for (int i = 0; i < numlines; i++) {
		for (int j = 0; j < vsize[i]; j++) {
			int numspace = wordlen[j] - code[i][j].size();
			cout << code[i][j];
			if (j < vsize[i] - 1)
				for (int k = 0; k < numspace; k++)
					cout << " ";
		}
		cout << endl;
	}
	return 0;
}