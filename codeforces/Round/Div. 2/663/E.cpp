#include <iostream>
#include <vector>

using namespace std;
const long maxn = 5 * 1e5 + 1;
long t, n, m, u, v;
vector<long> adj[maxn], bro[maxn];
long dep[maxn], par[maxn], vis[maxn];

void dfs(long x) {
    vis[x] = 1;
    for (long y: adj[x]) {
        if (vis[y]) continue;
        par[y] = x, dep[y] = dep[x] + 1;
        dfs(y);
    }
}

void cal() {
    dep[1] = 1;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (dep[i] >= (n + 1) / 2) {
            cout << "PATH" << endl << dep[i] << endl;
            while (i) {
                cout << i << " ";
                i = par[i];
            }
            cout << endl;
            return;
        }
        bro[dep[i]].push_back(i);
    }
    cout << "PAIRING" << endl;
    long cnt = 0;
    for (int i = 1; i <= n; i++) cnt += bro[i].size() >> 1;
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j + 1 < bro[i].size(); j += 2) {
            cout << bro[i][j] << " " << bro[i][j + 1] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear(), bro[i].clear();
            dep[i] = par[i] = vis[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cal();
    }
    return 0;
}
