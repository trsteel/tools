#include <iostream>
#include <string.h>
using namespace std;
const long maxn = 300001;
long t, n, a[maxn], cnt[maxn];

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        memset(cnt, 0, sizeof(cnt));
        for(int i=0;i<n;i++) {
            cin>>a[i]; cnt[a[i]]++;
        }
        string res(n, '0');
        if(cnt[1]>=1) res[n-1] = '1';
        res[0] = '1';
        for(int i=1;i<=n;i++) if(cnt[i]!=1) {
            res[0] = '0'; break;
        }
        long l = 0, r = n-1;
        for(int i=1;i<n;i++) {
            if(cnt[i]!=1) break;
            if(a[l]==i && cnt[i+1]) {
                l++; res[n-1-i] = '1';
            } else if(a[r]==i && cnt[i+1]) {
                r--; res[n-1-i] = '1';
            } else break;
        }
        cout<<res<<endl;
    }
    return 0;
}
