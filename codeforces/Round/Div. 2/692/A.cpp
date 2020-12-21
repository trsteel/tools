#include <iostream>

using namespace std;

int main() {
    long t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        long ans = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ')') break;
            ans++;
        }
        cout << (ans > (n - ans) ? "Yes" : "No") << endl;
    }
    return 0;
}
