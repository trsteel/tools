/**
 * 关键点: 对所有数lcm的每个因子，记录在某个数中出现最多的次数
 **/
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

const long maxn = 10001;
map<long long, long long> gcd[maxn];

void init() {
    for(long long i=1;i<maxn;i++) {
        long long ans = i;
        for(long long j=2;j<=ans;j++) {
            while(ans%j==0) {gcd[i][j]++; ans/=j;}
        }
    }
}

int main(){
    init();
    long long t, n, m; cin>>t;
    while(t--) {
        cin>>n>>m;
        long long num;
        vector<long long> cnt(maxn, 0);
        for(long long i=0;i<n;i++) {
            cin>>num;
            for(auto& it: gcd[num]) 
                cnt[it.first] = max(cnt[it.first], it.second);
        }
        long long res = 1, ans = 1;
        for(long long i=1;i<=m;i++) {
            long long tmp = 1;
            for(auto& it: gcd[i]) {
                long long d = max(0LL, it.second-cnt[it.first]);
                while(d--) tmp *= it.first;
            }
            if(tmp>ans) ans = tmp, res = i;
        }
        cout<<res<<endl;
    }
    return 0;
}