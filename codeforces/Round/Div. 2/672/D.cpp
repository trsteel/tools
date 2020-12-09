#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long maxn = 300005, mod = 998244353;
long long n, k, l, r, fact[maxn];

long long pw(long long a, long long b) {
    if (!b)return 1LL;
    if (b & 1)return (a * pw(a, b - 1)) % mod;
    long long x = pw(a, b >> 1LL);
    return (x * x) % mod;
}

long long C(long long n, long long k) {
    return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}

void init() {
    fact[0] = 1;
    for (long i = 1; i < maxn; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
}

int main() {
    init();
    cin >> n >> k;
    vector<pair<long long, bool>> pos;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        pos.emplace_back(l, false);
        pos.emplace_back(r, true);
    }
    sort(pos.begin(), pos.end());
    long long cnt = 0, ans = 0;
    for (auto p:pos) {
        if (p.second) {
            cnt--;
            continue;
        }
        if (++cnt >= k) {
            ans = ((ans + C(cnt, k) - (cnt != k ? C(cnt - 1, k) : 0)) % mod + mod) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
