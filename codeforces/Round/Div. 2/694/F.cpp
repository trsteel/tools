#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const long maxn = 300001;
long t, n, m, u, v;
vector<bool> vis, col;
vector<long> res;

void dfs(vector<long> adj[], long x) {
    vis[x] = true;
    if (!col[x]) {
        col[x] = true;
        res.push_back(x);
        for (long y: adj[x]) {
            col[y] = true;
        }
    }
    for (long y: adj[x]) {
        if (!vis[y]) dfs(adj, y);
    }
}

void solve() {
    cin >> n >> m;
    vector<long> adj[n + 1];
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    res.clear();
    vis = vector<bool>(n + 1, false);
    col = vector<bool>(n + 1, false);
    dfs(adj, 1);
    for (long i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl << res.size() << endl;
    for (long x: res) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
