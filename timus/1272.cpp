#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map<int, vector<int> > c;
bool v[10001];
set<int> not_visited;
queue<int> q;

void bfs() {
    int n = q.front();
    v[n] = true;
    not_visited.erase(n);
    q.pop();
    for (auto& i : c[n])
        if (!v[i])
            q.push(i);
    if (!q.empty())
        bfs();
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, k, m, a, b;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d", &a, &b);
        c[a].push_back(b);
        c[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) not_visited.insert(i);
    int cnt = 0;
    set<int>::iterator it;
    while ((it = not_visited.begin()) != not_visited.end()) {
        q.push(*it);
        bfs();
        ++cnt;
    }
    printf("%d\n", cnt - 1);
    return 0;
}