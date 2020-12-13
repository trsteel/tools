#include <iostream>

using namespace std;

int main() {
    long long t, x;
    cin >> t;
    while (t--) {
        cin >> x;
        long long res = 0, a = 1;
        while (a * (a + 1) / 2 <= x) {
            res++, x -= a * (a + 1) / 2;
            a = a*2 + 1;
        }
        cout<<res<<endl;
    }
    return 0;
}
