#include <iostream>

using namespace std;
const long maxn = 2001;
long n, m, dp[maxn][maxn];
char c[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    long res = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (j == 1 || c[i][j] != c[i][j - 2] || c[i][j] != c[i - 1][j - 1] || c[i][j] != c[i + 1][j - 1])
                dp[i][j] = 1;
            else dp[i][j] = min(dp[i][j - 2], min(dp[i - 1][j - 1], dp[i + 1][j - 1])) + 1;
            res += min(dp[i][j], c[i][j] == c[i][j - 1] ? dp[i][j - 1] + 1 : 1);
        }
    }
    cout << res << endl;
    return 0;
}