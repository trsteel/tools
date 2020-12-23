#include <iostream>
#include <vector>

using namespace std;

int main() {
    long t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long> cnt(26, 0);
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (char c: s) cnt[c - 'a']++;
        }
        bool valid = true;
        for (long i: cnt)
            if (i % n) {
                valid = false;
                break;
            }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}
