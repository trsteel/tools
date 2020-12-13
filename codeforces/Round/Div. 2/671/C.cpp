#include <iostream>

using namespace std;

int main() {
    long t, n, x, a[1001];
    cin >> t;
    while (t--) {
        cin >> n >> x;
        long res = 0, sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != x) {
                cnt++, sum += a[i];
            }
        }
        if (cnt > 0) {
            if (cnt * x == sum) res = 1;
            else if (cnt < n) res = 1;
            else res = 2;
        }
        cout << res << endl;
    }
    return 0;
}
