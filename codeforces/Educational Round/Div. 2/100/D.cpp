#include <iostream>

using namespace std;

int main() {
    long t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        long mi = 0, ma = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            mi = max(mi, 2 * i - x);
            ma = max(ma, x + 1 - 2 * i);
        }
        cout << n - ma - mi + 1 << endl;
    }
    return 0;
}
