#include <iostream>

using namespace std;

int main() {
    long n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    cout << sx << " " << sy << endl;
    for (int i = m; i > 0; i--) {
        if (i != sy)cout << sx << " " << i << endl;
    }
    long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == sx) continue;
        ans++;
        if (ans % 2) {
            for (int j = 1; j <= m; j++) cout << i << " " << j << endl;
        } else {
            for (int j = m; j > 0; j--) cout << i << " " << j << endl;
        }
    }
    return 0;
}
