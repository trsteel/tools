#include <iostream>

using namespace std;
long t, n, x, y;

long cal() {
    long d = y - x;
    for (long i = n - 1; i > 0; i--) {
        if (d % i == 0) return d / i;
    }
    return d;
}

int main() {

    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        long d = cal();
        for (long i = y; i > 0 && n > 0; i -= d, n--) {
            cout << i << " ";
        }
        for (long i = y + d; n > 0; i += d, n--) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
