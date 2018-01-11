/*
ID: wanying1
PROG: milk3
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool isVisited[21][21][21], isAns[21];

void dfs(vector<int> curr, vector<int> cap, int prevFrom, int prevTo) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (curr[i] == 0 || curr[j] == cap[j] || (i == prevFrom && j == prevTo) || (j == prevFrom && i == prevTo)) {
                continue;
            }
            int delta = min(curr[i], cap[j] - curr[j]);
            curr[i] -= delta;
            curr[j] += delta;
            if (curr[0] == 0) isAns[curr[2]] = true;
            if (!isVisited[curr[0]][curr[1]][curr[2]]) {
                isVisited[curr[0]][curr[1]][curr[2]] = true;
                dfs(curr, cap, i, j);
            }
            curr[i] += delta;
            curr[j] -= delta;
        }
    }
}

int main() {
    ofstream fout("milk3.out");
    ifstream fin("milk3.in");
    int na, nb, nc;
    fin >> na >> nb >> nc;
    int a = 0, b = 0, c = nc;
    isVisited[a][b][c] = true;
    isAns[c] = true;
    vector<int> curr(3), cap(3);
    curr[0] = curr[1] = 0, curr[2] = c;
    cap[0] = na, cap[1] = nb, cap[2] = nc;
    dfs(curr, cap, -1, -1);
    bool isFirst = true;
    for (int i = 0; i < 21; ++i) {
        if (isAns[i]) {
            if (isFirst) {
                fout << i;
                isFirst = false;
            }
            else {
                fout << ' ' << i;
            }
        }
    }
    fout << endl;
    return 0;
}
