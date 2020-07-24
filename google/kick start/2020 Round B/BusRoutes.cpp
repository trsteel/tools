#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long nums[1001], n, x;

bool match(long long d) {
    for(long long i=0;i<n;i++) {
        long long ans = d/nums[i];
        if(d%nums[i]) ans++;
        if(ans*nums[i]>x) return false;
        d = ans*nums[i];
    }
    return true;
}

int main(){
    long long t; cin>>t;
    for(long tt=1;tt<=t;tt++) {
        cin>>n>>x;
        for(int i=0;i<n;i++) cin>>nums[i];
        long long l=1, r=x, res=1;
        while(l<=r) {
            // cout<<l<<" "<<r<<endl;
            long long mid = (l+r)>>1;
            if(match(mid)) {
                res = max(res, mid);
                l = mid+1;
            } else r = mid-1;
        }
        cout<<"Case #"<<tt<<": "<<res<<endl;
    }
    return 0;
}