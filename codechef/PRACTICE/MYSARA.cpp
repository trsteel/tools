#include <iostream>

using namespace std;

const long maxn = 50001;
long mod = 1e9 + 7;
long nums[maxn];

long diff(long a, long b) {
    long res = 0;
    for(int i=0;i<32;i++) {
        long x = (a&(1<<i))>>i, y = (b&(1<<i))>>i;
        if(x==1&&y==0) return -1;
        if(x==1&&y==1) res++;
    }
    return res;
}

long power(long n, long mod) {
    long res = 1;
    for(long i=0;i<n;i++) {
        res = (res<<1)%mod;
    }
    return res;
}

int main(){
    long t, n; cin>>t;
    while(t--) {
        cin>>n;
        for(long i=0;i<n;i++) cin>>nums[i];
        long res = 0, ans;
        for(long i=1;i<n;i++) {
            ans = diff(nums[i-1], nums[i]);
            if(ans<0) { res=0; break; }
            res += ans;
        }
        if(res>0) res = power(res, mod);
        cout<<res<<endl;
    }
    return 0;
}