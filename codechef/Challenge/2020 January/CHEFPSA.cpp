/**
 * 关键点: 组合公式化简，输入输出用scanf/printf
 **/
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <stdio.h>
using namespace std;

vector<long> factorial(int n, long mod) {
    vector<long> res(n, 1);
    for(int i=1;i<n;i++) res[i] = (res[i-1]*i)%mod;
    return res;
}

vector<long> power(int n, long mod) {
    vector<long> res(n, 1);
    for(int i=1;i<n;i++) res[i] = (res[i-1]<<1)%mod;
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

long cal(vector<long>& vec, vector<long>& facts, vector<long>& pows, int n) {
    long sum = accumulate(vec.begin(), vec.end(), long(0));
    if(sum%(n+1) != 0) return 0;
    long avg = sum / (n+1);
    unordered_map<long, int> um;
    for(long i: vec) um[i]++;
    if(um[avg] < 2) return 0;
    um[avg] -= 2;
    long res = 1, mod = 1e9 + 7, N=n-1, ans;
    for(auto& it : um) {
        if(it.second==0) continue;
        if(it.first*2==avg) {
            if(it.second%2==1) return 0;
            ans = choose(facts, mod, N, it.second/2);
            res = (res*ans)%mod;
            N -= it.second/2;
        } else {
            if(um.find(avg-it.first)==um.end()) return 0;
            if(it.second != um[avg-it.first]) return 0;
            um[avg-it.first] = 0;
            ans = choose(facts, mod, N, it.second);
            ans = (ans*pows[it.second])%mod;
            // for(int i=0;i<it.second;i++) ans = (ans<<1)%mod;
            res = (res*ans)%mod;
            N -= it.second;
        }
    }
    return res;
}

int main(){
    auto facts = factorial(100001, 1e9+7);
    auto pows = power(100001, 1e9+7);
    int t, n; cin>>t;
    while(t--) {
        scanf("%d", &n);
        vector<long> vec(2*n);
        for(int i=0;i<2*n;i++) scanf("%ld", &vec[i]);
        printf("%ld\n", cal(vec, facts, pows, n));
    }
    return 0;
}