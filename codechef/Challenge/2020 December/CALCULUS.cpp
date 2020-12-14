#include <iostream>
using namespace std;

long long mod = 998244353;

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

int main() {
    // your code goes here
    long long n;
    cin>>n;
    if(n==1) cout<<2<<endl;
    long long res = 2;
    for(long long i=2;i<=n;i++) {
        res = (res+2*inv(2*i-1, mod)%mod)%mod;
    }
    cout<<res<<endl;
    return 0;
}
