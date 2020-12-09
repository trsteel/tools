#include <iostream>

using namespace std;
const long maxn = 300005;
long long t, n, q, a[maxn], x, y;

int f(int x) { return max(0LL, a[x] - a[x - 1]); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        long long res = 0;
        a[0] = a[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            res += f(i);
        }
        cout << res << endl;
        for (int i = 0; i < q; i++) {
            cin >> x >> y;
            res -= f(x) + f(x + 1) + (x + 1 < y) * f(y) + (x < y) * f(y + 1);
            swap(a[x], a[y]);
            res += f(x) + f(x + 1) + (x + 1 < y) * f(y) + (x < y) * f(y + 1);
            cout << res << endl;
        }
    }
    return 0;
}
