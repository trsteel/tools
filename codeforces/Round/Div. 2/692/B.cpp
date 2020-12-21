#include <iostream>

using namespace std;

bool match(long long n) {
    long long m = n;
    while (m > 0) {
        long long d = m % 10;
        if (d > 0 && n % d > 0) return false;
        m /= 10;
    }
    return true;
}

long long cal(long long n) {
    return match(n) ? n : cal(n + 1);
}

int main() {
    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << cal(n) << endl;
    }
    return 0;
}
