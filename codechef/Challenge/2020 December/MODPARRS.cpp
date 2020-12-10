#include <iostream>

using namespace std;

const long long mod = 998244353, p = 239;
long long n, a[21], vis[p];

long long dfs(long long i, long long sum) {
    if (i == n) return sum == 0 ? 1 : 0;
    long long res = 0;
    for (int j = 0; j < p; j++) {
        if (vis[j] != 0) continue;
        vis[j] = 1;
        res = (res + dfs(i + 1, (sum + j * a[i]) % p));
        vis[j] = 0;
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (long long &vi : vis) vi = 0;
    cout << dfs(0, 0) << endl;
    return 0;
}
