#include <iostream>

using namespace std;
const long maxn = 100001;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long long T, n, t[maxn], x[maxn];
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> t[i] >> x[i];
        long long p = 0, q = 0, ans = 0;
        for (long long i = 0, tp; i < n; i++) {
            if (p == q) q = x[i];
            if (i == n - 1 || t[i + 1] - t[i] >= abs(p - q)) tp = q;
            else tp = p < q ? p + t[i + 1] - t[i] : p - t[i + 1] + t[i];
            if (1LL * (x[i] - p) * (x[i] - tp) <= 0) ans++;
            p = tp;
//            cout<<i<<" "<<p<<" "<<q<<endl;
        }
        cout << ans << endl;
    }
    return 0;
}