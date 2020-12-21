#include <iostream>

using namespace std;

int main() {
    long t, n;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a >> b;
        long x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) y++;
            else if (a[i] > b[i]) x++;
        }
        cout << (x == y ? "EQUAL" : (x > y ? "RED" : "BLUE")) << endl;
    }
    return 0;
}
