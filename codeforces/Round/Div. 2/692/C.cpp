#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string.h>

using namespace std;

const long maxn = 100001;
long t, n, m, f[maxn];

long find(long x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) f[i] = i;
        long ans = 0, x, y;
        while (m--) {
            cin >> x >> y;
            if (x == y) continue;
            ans++;
            if (find(x) == find(y)) ans++;
            f[find(y)] = find(x);
        }
        cout << ans << endl;
    }
    return 0;
}
