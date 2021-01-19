#include <iostream>
#include <string.h>
#include <stack>

using namespace std;
const long maxn = (1L << 20) + 5;
long t, n, m, a[maxn], b[maxn];
bool vis[maxn];

long long dfs(long x) {
    if (!vis[x]) return 0;
    long long res = 0;
    for (long i = 0; i < n; i++) {
        if (vis[x | a[i]]) continue;
        vis[x | a[i]] = true;
        res += 1 + dfs(x | a[i]);
    }
    for (long i = 0; i < m; i++) {
        if (vis[x & b[i]]) continue;
        vis[x & b[i]] = true;
        res += 1 + dfs(x & b[i]);
    }
    return res;
}

long long solve() {
    vis[0] = true;
    long long res = 1;
    stack<long> st;
    st.push(0);
    while (!st.empty()) {
        long x = st.top();
        st.pop();
        for (long i = 0; i < n; i++) {
            long y = x | a[i];
            if (!vis[y]) {
                vis[y] = true, res++, st.push(y);
            }
        }
        for (long i = 0; i < m; i++) {
            long y = x & b[i];
            if (!vis[y]) {
                vis[y] = true, res++, st.push(y);
            }
        }
    }
//    for (long x = 0; x < maxn; x++) {
//        res += dfs(x);
//    }
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (long i = 0; i < n; i++) cin >> a[i];
        for (long i = 0; i < m; i++) cin >> b[i];
        memset(vis, 0, sizeof(vis));
        cout << solve() << endl;
    }
    return 0;
}
