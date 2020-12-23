#include <iostream>

using namespace std;

int main() {
    long long n, a[100001];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << 1 << " " << n << endl;
    cout << 0 << " ";
    for (int i = 1; i < n; i++) cout << (n * (n - 1 - a[i])) << " ";
    cout << endl;
    cout << 1 << " " << 1 << endl;
    cout << (-a[0]) << endl;
    if (n > 1) {
        cout << 2 << " " << n << endl;
        for (int i = 1; i < n; i++) cout << ((n - 1) * (a[i] - n)) << " ";
        cout << endl;
    } else {
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
    }

    return 0;
}
