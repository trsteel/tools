/**
 * 组合数计算公式
 **/

#include <iostream>
#include <vector>
using namespace std;

vector<long> factorial(int n, long mod) {
    vector<long> res(n, 1);
    for(int i=1;i<n;i++) res[i] = (res[i-1]*i)%mod;
    return res;
}

 long gcd(long a,long b){
    if(b==0) return a;
    return gcd(b,a%b);
 }

//扩展欧几里得定理：解ax+by==1。
void e_gcd(long a,long b,long &x,long &y) {
    if(!b) {
        x = 1, y=0;
        return;
    }
    e_gcd(b,a%b,x,y);
    long l=x;
    x=y;
    y=l-a/b*y;
}

long choose(vector<long>& facts, long mod, long n,long m) {
    if(m>n) return 0;
    if(n==m) return 1;
    long nn=facts[n], mm=(facts[m]*facts[n-m])%mod;
    long d=gcd(nn,mm);
    nn/=d, mm/=d;
    long x,y;
    e_gcd(mm,mod,x,y);
    x=(x+mod)%mod;
    return (x*nn)%mod;
}

int main(){
    long n, m, mod = 1e9+7;
    cin>>n>>m;
    auto facts = factorial(n+1, mod);
    cout<<choose(facts, mod, n, m)<<endl;
}