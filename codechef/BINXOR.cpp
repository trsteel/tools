#include <iostream>
#include <vector>
using namespace std;
long mod=1e9+7;
const long size = 100001;
long a[size];

void init() {
    a[0]=1;
    for(long i=1;i<size;i++) a[i]=(a[i-1]*i)%mod;
}

long one(string& a) {
    long res = 0;
    for(char c: a) if(c=='1') res++;
    return res;
}

 long gcd(long a,long b){
    if(b==0) return a;
    return gcd(b,a%b);
 }

//扩展欧几里得定理：解ax+by==1。
void e_gcd(long a,long b,long &x,long &y) {
    if(!b) x = 1, y=0;
    else {
        e_gcd(b,a%b,x,y);
        long l=x;
        x=y;
        y=l-a/b*y;
    }
 }

long choose(long n,long m)  
 {
    if(m>n) return 0;
    if(n==m) return 1;
    long nn=a[n],mm=(a[m]*a[n-m])%mod;
    long d=gcd(nn,mm);
    nn/=d;
    mm/=d;
    long x,y;
    e_gcd(mm,mod,x,y);
    x=(x+mod)%mod;
    return (x*nn)%mod;
 }

long cal(string& a, string& b) {
    long n = a.size();
    long one_a = one(a), one_b = one(b);
    long zero_a = n-one_a, zero_b = n-one_b;
    long l = n - min(zero_a, one_b) - min(zero_b, one_a); // 最少有多少零
    long r = min(zero_a, zero_b) + min(one_a, one_b); // 最多有多少零
    // cout<<l<<" "<<r<<endl;
    long res = 0;
    // 计算组合数
    // vector<vector<long> > cns(n+1, vector<long>(n+1, 0));
    // for(long i=0;i<=n;i++) {cns[0][i] = 0; cns[i][0] = 1;}
    // for(long i=1;i<=n;i++) for(long j=1;j<=r;j++) {
    //     cns[i][j] = (cns[i-1][j]+cns[i-1][j-1]) % mod;
    // }
    for(long k=l; k<=r; k+=2) {
        res = (res + choose(n, k))%mod;
    }
    return res;
}

int main(){
    init();
    long t; cin>>t;
    while(t--) {
        long n; cin>>n;
        string a, b; cin>>a>>b;
        cout<<cal(a, b)<<endl;
    }
    return 0;
}