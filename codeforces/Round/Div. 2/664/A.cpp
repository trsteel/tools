#include <iostream>

using namespace std;
long t, r, g, b, w;

bool cal() {
    if (r % 2 + g % 2 + b % 2 + w % 2 < 2) return true;
    if (r == 0 || g == 0 || b == 0) return false;
    r--, g--, b--, w += 3;
    return r % 2 + g % 2 + b % 2 + w % 2 < 2;
}

int main() {

    cin >> t;
    while (t--) {
        cin >> r >> g >> b >> w;
        cout << (cal() ? "Yes" : "No") << endl;
    }
    return 0;
}
