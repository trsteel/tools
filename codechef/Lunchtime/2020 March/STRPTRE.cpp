/**
 * 关键点: 逆元的求法
 **/
#include <iostream>

using namespace std;

long long mod = 1e9 + 7;
const long maxn = 100001;


void exgcd(long long a,long long b,long long& d,long long& x,long long& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

long long inv(long long a, long long p)
{
    long long d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}

long long cal(long long d) {
    long long res = 0, ans=1;
    for(long i=1;i<=d;i++) {
        ans = (ans<<1)%mod;
        res = (res+ans*((i+1)>>1))%mod;
    }
    ans = (ans<<1)%mod;
    long long v = (inv(ans-1, mod)*inv(ans-2, mod))%mod;
    // cout<<((c-1)*(c-2))<<" "<<res<<endl;
    return (v*res)%mod;
}

int main(){
    long long t, d; cin>>t;
    while(t--) {
        cin>>d;
        cout<<cal(d)<<endl;
    }
    return 0;
}