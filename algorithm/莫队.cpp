#include<iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 50005; // todo change here
// 莫队
int belong[maxn], nums[maxn], res[maxn];
struct Cmd {
    int id, l, r, k;
    friend bool operator < (const Cmd& a, const Cmd& b) {
        if(belong[a.l]==belong[b.l]) return a.r < b.r;
        return belong[a.l] < belong[b.l];
    }
} cmd[maxn];

// 区间计数
int times[maxn], num[maxn], cnt[maxn], all;
bool vis[maxn];
void add(int x) {
    ++num[++cnt[x]];
    times[++all]=cnt[x];
    --num[cnt[x]-1];
}

void del(int x) {
    ++num[--cnt[x]];
    times[++all]=cnt[x];
    --num[cnt[x]+1];
}

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void solve(int n, int m) {
    int L = 1, R = 0;
    for(int i=1;i<=m;i++) {
        while(R<cmd[i].r) add(nums[++R]);
        while(L>cmd[i].l) add(nums[--L]);
        while(R>cmd[i].r) del(nums[R--]);
        while(L<cmd[i].l) del(nums[L++]);
        int k = 0, ans = 0;
        for(int j=1;j <= all;j++) if(!vis[times[j]]&&num[times[j]]>0) {
            if(gcd(times[j],cmd[i].k)==1) ans+=num[times[j]];
            times[++k]=times[j];
            vis[times[j]]=true;
        }
        all=k;
        for(int j=1;j<=k;j++) vis[times[j]] = false;
        res[cmd[i].id]=ans;
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<endl;
}

int main() {
    int n, m; cin>>n>>m;
    int sq = sqrt(n);
    for(int i=1;i<=n;i++) {
        cin>>nums[i];
        belong[i] = (i-1)/sq + 1;
    }
    for(int i=1;i<=m;i++) {
        cin>>cmd[i].l>>cmd[i].r>>cmd[i].k;
        cmd[i].id = i;
    }
    sort(cmd+1, cmd+m+1);
    memset(times, 0, sizeof(times));
    memset(num, 0, sizeof(num));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    all = 0;
    solve(n, m);
    return 0;
}