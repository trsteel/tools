#include <iostream>
#include <algorithm>

using namespace std;
const long maxn = 2e5 + 10;
long n, k, h[maxn], f[maxn];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i];
    sort(h + 1, h + n + 1, greater<long>());
    long s = 0;
    f[0] = 1, f[1] = -1;
    for (long i = 0, pos = 1; i < maxn - 1; i++) {
        s += f[i], f[i + 1] += f[i];
        if (s + f[i + 1] >= k) {
            cout << i + 1 << endl;
            return 0;
        }
        while (f[i] && pos <= n) {
            long l = h[pos] / 2, r = (h[pos] - 1) / 2;
            f[i]--, s--;
            f[i + 2] += 2;
            f[i + l + 2]--, f[i + r + 2]--;
            pos++;
        }
    }
    cout << -1 << endl;
    return 0;
}
