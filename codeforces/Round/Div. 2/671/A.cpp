#include <iostream>

using namespace std;

int main() {
    long t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        bool win;
        if (n & 1) {
            win = false;
            for (int i = 0; i < n; i += 2)
                if ((s[i] - '0') & 1) {
                    win = true;
                    break;
                }
        } else {
            win = true;
            for (int i = 1; i < n; i += 2)
                if (((s[i] - '0') & 1) == 0) {
                    win = false;
                    break;
                }
        }
        cout << (win ? 1 : 2) << endl;
    }
    return 0;
}
