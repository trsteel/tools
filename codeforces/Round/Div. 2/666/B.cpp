#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, a[100001];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    long long res = -1;
    for (long long i = 1; i <= 100000; i++) {
        long long ans = 0, base = 1;
        for (int j = 0; j < n; j++) {
            ans += abs(base - a[j]);
            if (res > -1 && ans >= res) break;
            base *= i;
        }
        if (ans < res || res == -1) res = ans;
    }
    cout << res << endl;
    return 0;
}
