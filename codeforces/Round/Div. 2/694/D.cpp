#include <iostream>
#include <string.h>
using namespace std;
const long long maxn = 1e6 + 5;
long long t, n, q, x, a[maxn], o[maxn], cnt[maxn];

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    for(long long i=1;i<maxn;i++) {
        if(o[i]) continue;
        for(long long j=1;i*j*j<maxn;j++) {
            o[i*j*j] = i;
        }
    }
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>a[i]; a[i] = o[a[i]];
            cnt[a[i]]++;
        }
        long long mx = 0, mn = 0, res = 0;
        for(int i=0;i<n;i++) {
            mn = max(mn, cnt[a[i]]);
            if(a[i]==1 || (cnt[a[i]]&1)==0) {
                res += cnt[a[i]];
            }
            cnt[a[i]] = 0;
        }
        mx = max(res, mn);
        cin>>q;
        while(q--) {
            cin>>x;
            cout<<(x>0?mx:mn)<<endl;
        }
    }
    return 0;
}