#include <iostream>
#include <vector>
using namespace std;

bool match(vector<long>& d, long k, long mid) {
    long ans = 0;
    for(long i: d) {
        ans += i/mid;
        if(i%mid==0) ans--;
        // cout<<mid<<" "<<i<<" "<<ans<<endl;
        if(ans>k) return false;
    }
    // cout<<mid<<" "<<ans<<endl;
    return ans <= k;
}

int main(){
    long T, n, k, p; cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>k;
        long pre, ans, l=1, r = 0;
        cin>>pre;
        vector<long> d(n-1);
        for(long i=0;i<n-1;i++) {
            cin>>ans;
            d[i] = ans-pre;
            r = max(r, d[i]);
            pre = ans;
        }
        // for(long i: d) cout<<i<<" ";
        // cout<<endl;
        long res = r;
        while(l<=r) {
            long mid = (l+r)>>1;
            // cout<<l<<" "<<r<<endl;
            if(match(d, k, mid)) {
                res = min(res, mid);
                r = mid - 1;
            } else l = mid+1;
        }
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}