#include <iostream>
#include <vector>

using namespace std;
long t, n, k;
string s;

void cal() {
    long m = min(k, 20L);
    vector<bool> vis(1 << m, false);
    long run = 0;
    for (int i = 0; i + m <= n; i++) {
        if (run >= k - m) {
            long mask = 0;
            for (int j = 0; j < m; j++) {
                mask = (mask * 2) + ('1' - s[i + j]);
            }
            vis[mask] = true;
        }
        run = s[i] == '1' ? run + 1 : 0;
    }
    for (long mask = 0; mask < (1 << m); mask++) {
        if (vis[mask]) continue;
        cout << "YES" << endl;
        cout << string(k - m, '0');
        for (int j = m - 1; j >= 0; j--) {
            cout << ((mask >> j) & 1);
        }
        cout << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        cal();
    }
    return 0;
}
