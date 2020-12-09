#include <iostream>

using namespace std;

int main() {
    long t, n, a[50001];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        bool valid = false;
        for (int i = 1; i < n; i++) if (a[i - 1] <= a[i]) {
            valid = true; break;
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}
