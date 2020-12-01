#include <iostream>
#include <vector>

using namespace std;

const long maxn = 2e5 + 1;
long long a[maxn], cnt[maxn], sum[maxn], ans = 0;
vector<long> edges[maxn];

void dfs(int u) {
    sum[u] = a[u];
    for (auto v: edges[u]) {
        dfs(v);
        cnt[u] += cnt[v];
        sum[u] += sum[v];
    }
    if (edges[u].empty()) cnt[u] = 1;
    ans = max(ans, (sum[u] + cnt[u] - 1) / cnt[u]);
}

int main() {
    long n, x;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        edges[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
