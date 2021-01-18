#include <iostream>
#include <string.h>
using namespace std;
const long long mod = 998244353, maxn = 100001;
long long g[2][maxn];
pair<long long, long long> cache[maxn][2];
bool vis[maxn][2];

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

long long solve1(long long n, long long k) {
    if(n==1 || k==1) return 1;
    long long res = 1;
    for(long long i=2;i<=n;i++) {
        res = (res + (res+1)*(k-1)%mod)*inv(k, mod)%mod;
    }
    return res%mod;
}
long long cal(long long n) {
    long long res = g[0][0]==g[0][1]?1:2;
    for(long long i=1;i<n;i++) {
        if(g[0][i]==g[1][i]) {
            if(g[0][i-1]!=g[0][i]&&g[1][i-1]!=g[1][i])res++;
        } else {
            if(g[0][i-1]!=g[0][i]) res++;
            if(g[1][i-1]!=g[1][i]) res++;
        }
    }
    return res;
}
long long dfs1(long long n, long long k, long long i) {
    if(i==n) return cal(n);
    long long res = 0;
    for(long long x=1;x<=k;x++) {
        g[0][i] = x;
        for(long long y=1;y<=k;y++) {
            g[1][i] = y;
            res = (res+dfs1(n, k, i+1))%mod;
        }
    }
    return res;
}
pair<long long, long long> dfs(long long n, long long k, bool eq) {
    long long res = 0, cnt = 0;
    if(n==1) {
        if(eq) res = k, cnt = k;
        else res = 2*k*(k-1), cnt = k*(k-1);
        return make_pair(res%mod, cnt%mod);
    }
    if(vis[n][eq]) return cache[n][eq];
    auto p1 = dfs(n-1, k, true), p2 = dfs(n-1, k, false);
    if(eq) {
        // pre相等, cur相等，且联通数不变
        res += p1.first, cnt += p1.second;
        res %= mod, cnt %= mod;
        // pre相等, cur相等，且联通数+1
        res += (p1.first + p1.second)*(k-1)%mod;
        cnt += p1.second*(k-1)%mod;
        res %= mod, cnt %= mod;
        // pre相等, cur相等，且联通数+2
        // pre相等, cur不等, 且联通数不变
        res += p2.first*2, cnt += p2.second*2;
        res %= mod, cnt %= mod;
        // pre相等, cur不等，且联通数+1
        res += (p2.first + p2.second)*(k-2)%mod;
        cnt += p2.second*(k-2)%mod;
        res %= mod, cnt %= mod;
        // pre相等, cur不等，且联通数+2
    } else {
        // pre不等, cur相等, 且联通数不变
        // pre不等, cur相等, 且联通数+1
        res += (p1.first + p1.second)*2*(k-1)%mod;
        cnt += p1.second*2*(k-1)%mod;
        res %= mod, cnt %= mod;
        // pre不等, cur相等, 且联通数+2
        res += (p1.first + 2*p1.second)*(k-1)%mod*(k-2)%mod;
        cnt += p1.second*(k-1)%mod*(k-2)%mod;
        res %= mod, cnt %= mod;
        // pre不等, cur不等, 且联通数不变
        res += p2.first, cnt += p2.second;
        res %= mod, cnt %= mod;
        // pre不等, cur不等, 且联通数+1
        res += (p2.first+p2.second)*(k-2)%mod*2%mod;
        cnt += p2.second*(k-2)%mod*2%mod;
        res %= mod, cnt %= mod;
        // pre不等, cur不等, 且联通数+2
        long long tmp = (k-1)*(k-2)%mod + 1;
        res += (p2.first+2*p2.second)*tmp%mod;
        cnt += p2.second*tmp%mod;
        res %= mod, cnt %= mod;
    }
    // cout<<n<<" "<<eq<<" "<<res<<" "<<cnt<<endl;
    vis[n][eq] = true;
    return cache[n][eq] = make_pair(res%mod, cnt%mod);
}

long long cal(long long n, long long k) {
    auto p1 = dfs(n, k, true), p2 = dfs(n, k, false);
    // cout<<n<<" "<<p1.first<<" "<<p2.first<<endl;
    return (p1.first + p2.first)%mod;
}

long long solve2(long long n, long long k) {
    if(k==1) return 1;
    long long iv = inv(k, mod);
    long long iv2 = iv*iv%mod;
    memset(vis, 0, sizeof(vis));
    long long res = cal(n, k);
    for(long long i=0;i<n;i++) res = res*iv2%mod;
    return res;
}

int main(){
    long long m, n, k;
    // while(1) { 
        cin>>m>>n>>k;
        cout<<(m==1?solve1(n, k):solve2(n, k))<<endl;
    // }
    return 0;
}