#include <iostream>
#include <vector>
using namespace std;

long long mod = 998244353;

vector<long long> factorial(long long n, long long mod) {
    vector<long long> res(n, 1);
    for(long long i=1;i<n;i++) res[i] = (res[i-1]*i)%mod;
    return res;
}

 long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
 }

//扩展欧几里得定理：解ax+by==1。
void e_gcd(long long a,long long b,long long &x,long long &y) {
    if(!b) {
        x = 1, y=0;
        return;
    }
    e_gcd(b,a%b,x,y);
    long long l=x;
    x=y;
    y=l-a/b*y;
}

long long choose(vector<long long>& facts, long long mod, long long n,long long m) {
    if(m>n) return 0;
    if(n==m) return 1;
    long long nn=facts[n], mm=(facts[m]*facts[n-m])%mod;
    long long d=gcd(nn,mm);
    nn/=d, mm/=d;
    long long x,y;
    e_gcd(mm,mod,x,y);
    x=(x+mod)%mod;
    return (x*nn)%mod;
}

long long pow2(long long k) {
    long long res = 1;
    for(long long i=0;i<k;i++) {
        res = (res<<1)%mod;
    }
    return res;
}

int main(){
    long long n, m;
    cin>>n>>m;
    if(n==2) {cout<<0<<endl; return 0;}
    auto facts = factorial(m+1, mod);
    long long res = choose(facts, mod, m, n-1);
    res = (res*pow2(n-3))%mod;
    res = (res*(n-2))%mod;
    cout<<res<<endl;
    return 0;
}