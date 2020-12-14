#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const long maxn = 100001;
long t, n, a, b;
vector<long> adj[maxn];
unordered_map<long, long> um[maxn];

long dfs(int x, int pre) {
    long res = 1;
    for (int y: adj[x]) {
        if (y == pre) continue;
        if (um[x].count(y) == 0) um[x][y] = dfs(y, x);
        res += um[x][y];
    }
    return res;
}

void solve() {
    queue<int> qu;
    for (int i = 1; i <= n; i++) {
        for (int y: adj[i]) {
            if(um[i].count(y)) continue;
            um[i][y] = dfs(y, i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j: adj[i]) {
            if (um[i][j] != um[j][i]) continue;
            for (int k: adj[j]) if(k!=i) {
                cout << j << " " << k << endl;
                cout << i << " " << k << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j: adj[i]) {
            cout << i << " " << j << endl;
            cout << i << " " << j << endl;
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            um[i].clear();
        }
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        solve();
    }
    return 0;
}
