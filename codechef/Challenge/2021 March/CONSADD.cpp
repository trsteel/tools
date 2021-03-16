#include <iostream>

using namespace std;

const long maxn = 1001;
long t, r, c, x, a[maxn][maxn], b[maxn][maxn];

bool cal() {
    for (int i = 0; i + x <= r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 0) continue;
            int d = a[i][j];
            for (int k = 0; k < x; k++) {
                a[i + k][j] -= d;
            }
        }
    }
    for (int i = r - x + 1; i < r; i++) {
        for (int j = 0; j + x <= c; j++) {
            if (a[i][j] == 0) continue;
            int d = a[i][j];
            for (int k = 0; k < x; k++) {
                a[i][j + k] -= d;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 0) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> r >> c >> x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cin >> a[i][j];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cin >> b[i][j];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) a[i][j] -= b[i][j];
        }
        cout << (cal() ? "Yes" : "No") << endl;
    }
    return 0;
}
