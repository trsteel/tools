#include <iostream>
#include <algorithm>

using namespace std;
const long maxn = 200001;
long long n, m, a[maxn], b[maxn];

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    long long ans = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) continue;
        if (ans == -1) ans = a[i] - a[i - 1];
        else ans = min(ans, gcd(ans, a[i] - a[i - 1]));
    }
    for (int i = 0; i < m; i++) {
        cout << (ans == -1 ? (a[0] + b[i]) : gcd(ans, a[0] + b[i])) << " ";
    }
    cout << endl;
    return 0;
}
