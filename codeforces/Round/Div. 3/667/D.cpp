#include <iostream>

using namespace std;

long long t, n, s;

long long digit(long long x) {
    long long res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

long long dfs(long long x) {
    if (x >= n && digit(x) <= s) return x;
    long long base = 1;
    while (x % (base * 10) == 0) base *= 10;
    return dfs(x + base);
}

long long cal() {
    long long res = dfs(n);
    return res - n;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        cout << cal() << endl;
    }
    return 0;
}
