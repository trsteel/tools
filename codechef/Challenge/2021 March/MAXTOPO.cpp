#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
const long long maxn = 500001, mod = 1e9 + 7;
long long t, n, k, u, v, fac[maxn], ifac[maxn];
vector<int> adj[maxn];
unordered_map<int, int> cnt[maxn];

void exgcd(long long a, long long b, long long &d, long long &x, long long &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

long long inv(long long a, long long p) {
    long long d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x + p) % p : -1;
}

int dfs(int x, int pre) {
    int sum = 0;
    for (int y: adj[x])
        if (y != pre) {
            cnt[x][y] = dfs(y, x);
            sum += cnt[x][y];
        }
    if (pre != -1) cnt[x][pre] = n - 1 - sum;
    return sum + 1;
}

int find_first() {
    int x = 1;
    bool find = true;
    while (find) {
        find = false;
        for (int y: adj[x]) {
            if (cnt[x][y] * 2 > n) {
                x = y, find = true;
                break;
            } else if (cnt[x][y] * 2 == n && x < y) {
                x = y, find = true;
                break;
            }
        }
    }
    return x;
}

int find_second(int x) {
    int res = 1, c = -1;
    for (auto &it: cnt[x]) {
        int y = it.first, ans = it.second;
        if (ans > c) res = y, c = ans;
        else if (ans == c && y > res) res = y, c = ans;
    }
    return res;
}

long long cal2(int x, int pre) {
    long long a = 0, b = 1;
    for (auto &it: cnt[x]) {
        if (it.first != pre) {
            b = b * ifac[it.second] % mod;
            a += it.second;
        }
    }
    return fac[a] * b % mod;
}

long long cal(int x, int pre) {
    long long res = 1;
    for (int y: adj[x]) {
        if (y != pre) {
            res = res * cal(y, x) % mod;
        }
    }
    res = res * cal2(x, pre) % mod;
    return res;
}

void init() {
    fac[0] = fac[1] = 1, ifac[0] = ifac[1] = 1;
    for (long long i = 2; i < maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = inv(fac[i], mod);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init();
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            cnt[i].clear();
        }
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        int x = find_first();
        if (k == 2) {
            x = find_second(x);
        }
        cout << x << " " << cal(x, -1) << endl;
    }
    return 0;
}
