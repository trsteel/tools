#include <iostream>
#include <algorithm>

using namespace std;
long t, n, a, cnt[200002];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i <= n; i++) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> a;
            cnt[a]++;
        }
        sort(cnt, cnt + n + 1);
        int i = n;
        while (cnt[i] == cnt[n]) i--;
        cout << i / (cnt[n] - 1) - 1 << endl;
    }
    return 0;
}