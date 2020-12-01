#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long const maxn = 300001;
long long n, a[maxn], fac[maxn], inv[maxn], mod = 998244353;

long long qpow(long long x, long long k) {
    long long res = 1;
    while(k) {
        if(k&1) res = res*x%mod;
        k >>= 1;
        x=x*x%mod;
    }
    return res;
}

int main() {
    cin>>n;
    for(long long i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1, a+2*n+1);
    fac[0] = 1, inv[0] = 1;
    for(long long i=1;i<=2*n;i++) {
        fac[i] = fac[i-1]*i%mod;
        inv[i] = qpow(fac[i], mod-2);
    }
    long long inc = fac[n<<1]*inv[n]%mod*inv[n]%mod;
    long long ans = 0;
    for(long long i=1;i<=n;i++) ans = (ans-inc*a[i]%mod)%mod;
    for(long long i=n+1;i<=2*n;i++) ans = (ans+inc*a[i]%mod)%mod;
    cout<<(ans+mod)%mod<<endl;
    return 0;
}