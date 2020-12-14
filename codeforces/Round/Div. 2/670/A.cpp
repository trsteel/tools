#include <iostream>
#include <string.h>

using namespace std;

int main() {
    long t, n, a, cnt[101];
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a;
            cnt[a]++;
        }
        int res = 0;
        for (int i = 0; i < 101; i++) {
            if (cnt[i] == 0) {
                res += i; break;
            }
            cnt[i]--;
        }
        for (int i = 0; i < 101; i++) {
            if (cnt[i] == 0) {
                res += i; break;
            }
            cnt[i]--;
        }
        cout<<res<<endl;
    }
    return 0;
}
