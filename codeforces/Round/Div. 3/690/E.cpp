#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long maxn = 200001, mod = 1e9 + 7;
long long t, n, m, k;

vector<long long> factorial(int n, long long mod) {
    vector<long long> res(n, 1);
    for(int i=1;i<n;i++) res[i] = (res[i-1]*i)%mod;
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

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    auto facts = factorial(maxn, mod);
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        vector<long long> a(n);
        for(long long& i: a) cin>>i;
        sort(a.begin(), a.end());
        long long res = 0;
        for(long long i=0;i<n;i++) {
            long long j = upper_bound(a.begin(), a.end(), a[i]+k) - a.begin();
            while(j==n || a[j] > a[i]+k) j--;
            long long d = j-i;
            res = (res+choose(facts, mod, d, m-1))%mod;
        }
        cout<<res<<endl;
    }
    return 0;
}