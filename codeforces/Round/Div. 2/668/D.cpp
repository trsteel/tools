#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long maxn = 100001;

long long t, n, a, b, da, db, u, v;
vector<long> adj[maxn];

pair<long, long> dfs(long i, long pre) {
    long dep = 0, res = 0;
    priority_queue<long, vector<long>, greater<>> pq;
    for (long j: adj[i]) {
        if (j == pre) continue;
        auto p = dfs(j, i);
        pq.push(p.second);
        if (pq.size() > 2) pq.pop();
        res = max(res, p.first);
    }
    long ans = 1;
    while (!pq.empty()) {
        long x = pq.top();
        pq.pop();
        dep = max(dep, x);
        ans += x;
    }
    res = max(res, ans);
    return {res, dep + 1};
}

long dis() {
    for (long i = 1; i <= n; i++)
        if (adj[i].size() == 1) {
            return dfs(i, -1).first;
        }
    return -1;
}

long dfs2(long u, long v, long pre) {
    if (u == v) return 0;
    for (long w: adj[u]) {
        if (w == v) return 1;
        if (w == pre) continue;
        long ans = dfs2(w, v, u);
        if (ans != -1) return 1 + ans;
    }
    return -1;
}

bool cal() {
    long ans = dfs2(a, b, -1);
    if (ans <= da) return true;
    long d = dis() - 1;
    if (d <= 2 * da) return true;
    return db <= 2 * da;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << (cal() ? "Alice" : "Bob") << endl;
    }
    return 0;
}