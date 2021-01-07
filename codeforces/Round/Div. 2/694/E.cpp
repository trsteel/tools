#include <iostream>
#include <cmath>

using namespace std;
long n, k, x;

long ask(long idx) {
    cout << "? " << (idx + 1) << endl;
    cin >> x;
    return x;
}

int main() {
    cin >> n >> k;
    long sq = max(long(sqrt(n)), 1L);
    if (n % sq == 0) sq++;
    long idx = 0;
    while (ask(idx) == k) {
        idx = (idx + sq) % n;
    }
    if (x > k) {
        do {
            idx = (idx - 1 + n) % n;
        } while (ask(idx) != k);
    } else {
        do {
            idx = (idx + 1) % n;
        } while (ask(idx) != k);
    }
    cout << "! " << (idx + 1) << endl;
    return 0;
}
