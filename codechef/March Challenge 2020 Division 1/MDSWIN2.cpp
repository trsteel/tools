/**
 * 涉及算法: 莫队、高效计数、组合数
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

long mod = 998244353;
const long maxn = 100001;
long facts[maxn];
long nums[maxn];

const long midn = 10001;
long comb[midn][midn];

long belong[maxn];
struct Cmd {
    long l, r, id;
    friend bool operator < (const Cmd& a, const Cmd& b) {
        if(belong[a.l]==belong[b.l]) return a.r < b.r;
        return belong[a.l] < belong[b.l];
    }
} cmd[maxn];

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

long choose(long mod, long n,long m) {
    if(n<midn) return comb[n][m];
    if(m==1 || m==n-1) return n;
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

// 区间计数
long times[maxn], num[maxn], cnt[maxn], all;
bool vis[maxn];
void add(long x) {
    ++num[++cnt[x]];
    times[++all]=cnt[x];
    --num[cnt[x]-1];
}

void del(long x) {
    ++num[--cnt[x]];
    times[++all]=cnt[x];
    --num[cnt[x]+1];
}


long cal() {
    long k = 0;
    vector<long> vec;
    for(long j=1;j <= all;j++) if(!vis[times[j]]&&num[times[j]]>0) {
        vec.push_back(times[j]);
        times[++k]=times[j];
        vis[times[j]]=true;
    }
    all=k;
    for(int j=1;j<=k;j++) vis[times[j]] = false;
    long sum = 0;
    for(long i: vec) if(num[i]%2) sum ^= i;
    // for(long i: vec) cout<<i<<"a"<<num[i]<<" ";
    // cout<<sum<<endl; 
    if(sum==0) return 0;
    long res = 0, ans, tmp;
    for(long i: vec) if(num[i]>0) {
        ans = sum^i;
        if(ans > i) continue;
        tmp = choose(mod, i, i-ans);
        tmp = (tmp*num[i])%mod;
        res = (res+tmp)%mod;
    }
    return res;
}

void solve(long m) {
    long L = 1, R = 0;
    vector<long> res(m+1);
    for(int i=1;i<=m;i++) {
        for(;R<cmd[i].r;R++) add(nums[R+1]);
        for(;L>cmd[i].l;L--) add(nums[L-1]);
        for(;R>cmd[i].r;R--) del(nums[R]);
        for(;L<cmd[i].l;L++) del(nums[L]);
        // cout<<cmd[i].l<<" "<<cmd[i].r<<": ";
        res[cmd[i].id] = cal();
    }
    for(int i=1;i<=m;i++) printf("%ld\n", res[i]);
}
void init() {
    facts[0] = 1;
    for(int i=1;i<maxn;i++) facts[i] = (facts[i-1]*i)%mod;
    
    for(int i=0;i<midn;i++) {
        comb[0][i] = 0; comb[i][0] = 1;
    }
    for(int i=1;i<midn;i++) for(int j=1;j<=i;j++) {
        comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
    }
}

int main(){
    init();
    long t, n, q, l, r; cin>>t;
    while(t--) {
        scanf("%ld", &n); long sq = sqrt(n);
        for(int i=1;i<=n;i++) {
            scanf("%ld", &nums[i]); belong[i] = (i-1)/sq+1;
        }
        unordered_map<long, long> um;
        for(int i=1;i<=n;i++) {
            if(um.find(nums[i])==um.end()) um[nums[i]] = um.size();
            nums[i] = um[nums[i]];
        }
        scanf("%ld", &q);
        for(int i=1;i<=q;i++) {
            scanf("%ld%ld", &cmd[i].l, &cmd[i].r);
            cmd[i].id = i;
        }
        memset(times, 0, sizeof(times));
        memset(num, 0, sizeof(num));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        all = 0;
        sort(cmd+1, cmd+q+1);
        solve(q);
    }
    return 0;
}