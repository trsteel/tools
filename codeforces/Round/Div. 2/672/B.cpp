#include <iostream>
#include <vector>

using namespace std;

int bit(long long a) {
    for (int j = 30; j >= 0; j--) if (a & (1LL << j)) return j;
    return 0;
}

int main() {
    long long t, n, a;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> cnt(30, 0);
        for (int i = 0; i < n; i++) {
            cin >> a;
            cnt[bit(a)]++;
        }
        long long res = 0;
        for (long long i: cnt) res += i * (i - 1) / 2;
        cout << res << endl;
    }
    return 0;
}
