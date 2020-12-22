#include <iostream>

using namespace std;

int main() {
    long long t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        long long res = (b - a) / 10;
        if ((b - a) % 10) res++;
        cout << res << endl;
    }
    return 0;
}
