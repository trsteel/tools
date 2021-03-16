#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
const long maxn = 1e9 + 1;
const long maxm = 200001;
long t, n, m, x, y;
long a[maxm], b[maxm], c[maxm], d[maxm], idx[maxm];
bool vis[maxm];

bool find(queue<int> &q, long l, long r) {
    for (long i = 0; i < m; i++) {
        long id = idx[i];
        if (a[id] > r) break;
        if (b[id] < l) continue;
        if (y >= c[id] && y <= d[id]) return true;
        if (!vis[id]) q.push(id), vis[id] = true;
    }
    return false;
}

long cal() {
    if (x == y) return 0;
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    if(find(q, x, x)) return 1;
    long step = 2;
    while (!q.empty()) {
        long size = q.size();
        while (size--) {
            int id = q.front();
            q.pop();
            if(find(q, c[id], d[id])) return step;
        }
        step++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        for (int i = 0; i < m; i++) {
            idx[i] = i;
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        }
        sort(idx, idx + m, [&a](int i, int j) {
            return a[i] < a[j];
        });
        cout << cal() << endl;
    }
    return 0;
}
