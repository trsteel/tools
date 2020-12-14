#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;
const long maxn = 1010;

long cal(string &s) {
    long n = s.size();
    unordered_set<long> us[n + 1];
    for (long i = 0; i < n; i++) {
        string ans = "";
        long last = -1, pre = -1;
        for (long j = i; j < n; j++) {
            ans.push_back(s[j]);
            while (last + 1 < ans.size() && ans[last + 1] == '1') last++;
            if (s[j] == '0') {
                us[ans.size()].insert((last+1)*maxn+pre+1);
                continue;
            }
            if (pre <= last) {
                pre = ans.size() - 1;
                us[ans.size()].insert((last+1)*maxn+pre+1);
                continue;
            }
            swap(ans[last + 1], ans[ans.size() - 1]);
            swap(ans[pre], ans[ans.size() + last - pre]);
            pre = ans.size() + last - pre;
            while (last + 1 < ans.size() && ans[last + 1] == '1') last++;
            us[ans.size()].insert((last+1)*maxn+pre+1);
        }
    }
    long res = 0;
    for (int i = 0; i <= n; i++) res += us[i].size();
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << cal(s) << endl;
    }
    return 0;
}
