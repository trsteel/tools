#include <iostream>
#include <cstring>

using namespace std;
const long long maxn = 1001;
long long t, n, x, y, a[maxn];
bool dp[maxn][maxn];

long long comp(long long i, long long j) {
    if (i == -1) return j;
    if (j == -1) return i;
    return min(i, j);
}

long long dfs(long long i, long long p, long long num) {
    if (p < 0 || i < num || !dp[i][p]) return -1;
    if (p == 0) return i == num ? num : -1;
    long res = -1;
    if (num > 0) {
        res = comp(res, dfs(i - 1, p - a[i - 1], num - 1));
    }
    for (long j = 1; j <= i; j++) {
        p -= a[i - j];
        res = comp(res, dfs(i - j, p, num + j));
    }
    return res;
}

long long find(long long i, long long p) {
    if (p < 0 || !dp[i][p]) return -1;
    long res = find(i - 1, p - a[i - 1]);
    for (long long j = 0; j <= i; j++) {
        if (j > 0) p -= a[i - j];
        if (dfs(i - j, p, j)) {
            res = comp(res, j);
            break;
        }
    }
    return res;
}

long long solve() {
    for (long long i = 0; i <= n; ++i) {
        for (long long p = 0; p <= y; ++p) {
            dp[i][p] = p == 0;
            if (i > 0 && p >= a[i - 1] && !dp[i][p]) {
                dp[i][p] = dp[i - 1][p - a[i - 1]];
            }
        }
    }
    long long res = -1;
    for (long long i = 0; i <= n; i++) {
        for (long long p = x; p <= y; p++) {
            res = comp(res, find(i, p));
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve() << endl;
    }
    return 0;
}