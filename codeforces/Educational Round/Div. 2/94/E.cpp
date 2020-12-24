#include <iostream>

using namespace std;
long n, a[5001];

long dfs(long l, long r) {
    if (l > r) return 0;
    if (l == r) return min(a[l], 1L);
    long pos = -1, mi = 1e9 + 7;
    for (int i = l; i <= r; i++) {
        if (mi <= a[i]) continue;
        mi = a[i], pos = i;
    }
    for (int i = l; i <= r; i++) a[i] -= mi;
    return min(r - l + 1, dfs(l, pos - 1) + dfs(pos + 1, r) + mi);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << dfs(0, n - 1) << endl;
    return 0;
}
