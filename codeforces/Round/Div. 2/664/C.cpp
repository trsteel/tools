#include <iostream>

using namespace std;
long n, m, a[201], b[201];

bool valid(long x, long i) {
    for (int j = 0; j < m; j++) {
        if ((x | (a[i] & b[j])) == x) return true;
    }
    return false;
}

bool find(long x) {
    for (int i = 0; i < n; i++) {
        if (!valid(x, i)) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (long i = 0; i <= 1024; i++) {
        if (find(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
