
#include <iostream>

using namespace std;


long long t, a, b, x, y, n;

long long cal() {
    if (a + b <= x + y + n) return x * y;
    long long res = a * b;
    if (a <= x + n) res = min(res, x * (b - (n + x - a)));
    else res = min(res, (a - n) * b);
    if (b <= y + n) res = min(res, (a - (n + y - b)) * y);
    else res = min(res, a * (b - n));
    return res;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> x >> y >> n;
        cout << cal() << endl;
    }
    return 0;
}
