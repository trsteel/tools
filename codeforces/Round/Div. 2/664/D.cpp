#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
long long n, d, m, a;
vector<long long> l, r;

long long find(vector<long long> &sum, long s) {
    if (s > n) return 0;
    long long t = (n - s + 1) / (d + 1);
    if (t > r.size()) t = r.size();
    long long res = sum[t];
    if (s + t * (d + 1) <= n && t < r.size()) res += r[t];
    return res;
}

int main() {
    cin >> n >> d >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a <= m) l.push_back(a);
        else r.push_back(a);
    }
    sort(l.begin(), l.end(), greater<>());
    sort(r.begin(), r.end(), greater<>());
    vector<long long> sum(r.size() + 1, 0);
    for (int i = 0; i < r.size(); i++) sum[i + 1] = sum[i] + r[i];
    long long res = find(sum, 1), ans = 0;
    for (int i = 0; i < n && i < l.size(); i++) {
        ans += l[i];
        res = max(res, ans + find(sum, i + 2));
    }
    cout << res << endl;
    return 0;
}
