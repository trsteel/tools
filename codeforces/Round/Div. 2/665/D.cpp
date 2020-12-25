#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long maxn = 100010, mod = 1e9 + 7;
long long t, n, u, v, m, p[maxn];
vector<long long> adj[maxn], conn;

long long dfs(long long x, long long pre) {
    long long res = 1;
    for (long long y: adj[x]) {
        if (y == pre) continue;
        long long ans = dfs(y, x);
        conn.push_back(ans * (n - ans));
        res += ans;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (long long i = 1; i <= n; i++) adj[i].clear();
        for (long long i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> m;
        for (long long i = 0; i < m; i++) {
            cin >> p[i];
        }
        sort(p, p + m);
        while (m > n - 1) {
            p[m - 2] = p[m - 2] * p[m - 1] % mod;
            m--;
        }
        conn.clear();
        dfs(1, -1);
        sort(conn.begin(), conn.end());
        long long res = 0, d = conn.size() - m;
        for (long long i = 0; i < conn.size(); i++) {
            if (i < d) res = (res + conn[i] % mod) % mod;
            else res = (res + p[i - d] * (conn[i] % mod) % mod) % mod;
        }
        cout << res << endl;
    }
    return 0;
}
