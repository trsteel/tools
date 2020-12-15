#include <iostream>
#include <stack>

using namespace std;

const long maxn = 300001;
long n, a[maxn], dp[maxn];
stack<int> q, q1;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = n + 1;
    }
    dp[0] = 0;
    q.push(0), q1.push(0);
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i - 1] + 1, dp[i]);
        while (!q.empty() && a[q.top()] <= a[i]) {
            int x = a[q.top()];
            q.pop();
            if (a[i] == x) continue;
            if (!q.empty()) {
                dp[i] = min(dp[i], dp[q.top()] + 1);
            }
        }

        while (!q1.empty() && a[q1.top()] >= a[i]) {
            int x = a[q1.top()];
            q1.pop();
            if (x == a[i]) continue;
            if (!q1.empty()) {
                dp[i] = min(dp[i], dp[q1.top()] + 1);
            }
        }

        q.push(i);
        q1.push(i);
    }
    cout << dp[n - 1] << endl;
    return 0;
}
