#include <iostream>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <stdio.h>
using namespace std;
long long mod = 1e9 + 7;
long long l[4001], idx[4001], query[501], res[501], q, n, maxq;
vector<long long> adj[4001];

long long power(long long base, long long n) {
    long long res = 1;
    while(n--) res = (res*base)%mod;
    return res;
}

long long dfs(long long i, long long step) {
    if(step==0) return 1;
    if(i==0) return power(l[idx[i]], step);
    long long res = 0, p = 1;
    for(long long j=0;j<=step;j++) {
        res = (res+dfs(i-1, step-j)*p%mod)%mod;
        p = p*l[idx[i]]%mod;
    }
    // cout<<i<<" "<<step<<res<<endl;
    return res;
}

void cal(long long size) {
    for(long long i=0;i<q;i++) if(query[i]>=size) {
        res[i] = (res[i]+dfs(size, query[i]-size))%mod;
    }
}

void dfs(long long u, long long n, long long size) {
    idx[size++] = u;
    if(u!=n) {
        for(long long v: adj[u]) dfs(v, n, size);
    } else {
        cal(size-1);
    }
}

int main(){
    long long m, u, v;
    cin>>n>>m>>q;
    for(long long i=1;i<=n;i++) scanf("%lld", &l[i]);
    for(long long i=0;i<m;i++) {
        scanf("%lld%lld", &u, &v);
        if(u>v) swap(u, v);
        adj[u].push_back(v);
    }
    maxq = 0;
    for(long long i=0;i<q;i++) {
        cin>>query[i];
        maxq = max(maxq, query[i]);
    }
    dfs(1, n, 0);
    for(long long i=0;i<q;i++) printf("%lld\n", res[i]);
    return 0;
}