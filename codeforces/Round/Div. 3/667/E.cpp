#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const long maxn = 200001;
long long t, n, k, x[maxn], y[maxn];
map<long long, long long> dpl, dpr;

long long find_l(long long a) {
    auto it = dpl.upper_bound(a);
    if (it != dpl.begin()) it--;
    if (it->first > a) return 0;
    return it->second;
}

long long find_r(long long a) {
    auto it = dpr.lower_bound(a);
    if (it == dpr.end()) return 0;
    return it->second;
}

long long cal() {
    sort(x, x + n);
    dpl.clear(), dpr.clear();
    long long pre = 0, ans = 0;
    for (long i = 0; i < n; i++) {
        while (x[pre] + k < x[i]) pre++;
        dpl[x[i]] = max(ans, i - pre + 1);
        ans = max(ans, dpl[x[i]]);
    }
    pre = n - 1, ans = 0;
    for (long i = n - 1; i >= 0; i--) {
        while (x[pre] > x[i] + k) pre--;
        dpr[x[i]] = max(ans, pre - i + 1);
        ans = max(ans, dpr[x[i]]);
    }
    long long res = max(dpl.end()->second, dpr.begin()->second);
    for (long i = 0; i < n; i++) {
        res = max(res, find_l(x[i]) + find_r(x[i] + 1));
        res = max(res, find_l(x[i] - 1) + find_r(x[i]));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> y[i];
        cout << cal() << endl;
    }
    return 0;
}
