#include <iostream>
#include <vector>
#include <climits>

using namespace std;
long n, m;
vector<vector<char>> g;

long find(long y, long d) {
    long res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(long(g[i][y] - '0') - (d & 1));
        d >>= 1;
    }
    return res;
}

bool valid(long x, long y) {
    for (int i = 0; i < n - 1; i++) {
        long ans = (x & 1) + (y & 1) + ((x >> 1) & 1) + ((y >> 1) & 1);
        if (ans % 2 == 0) return false;
        x >>= 1, y >>= 1;
    }
    return true;
}

long cal() {
    if (n == 1 || m == 1) return 0;
    if (n > 3 && m > 3) return -1;
    long sz = 1 << n;
    vector<long> dp1(sz), dp2;
    for (int i = 0; i < sz; i++) {
        dp1[i] = find(0, i);
    }
    for (int i = 1; i < m; i++) {
        dp2 = vector<long>(sz, INT_MAX);
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                if (dp1[j] == INT_MAX || !valid(j, k)) continue;
                dp2[k] = min(dp2[k], dp1[j] + find(i, k));
            }
        }
        dp1 = move(dp2);
    }
    long res = INT_MAX;
    for (long i: dp1) res = min(res, i);
    return res;
}

int main() {
    cin >> n >> m;
    if (n <= m) {
        g = vector<vector<char>>(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> g[i][j];
        }
    } else {
        g = vector<vector<char>>(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> g[j][i];
        }
        swap(n, m);
    }
    cout << cal() << endl;
    return 0;
}
