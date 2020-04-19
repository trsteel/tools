
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;

const long maxn = 100001;
const long maxa = 1000001;
const long maxg = 1001;
long long mod = 1e9 + 7;

vector<long> adj[maxn];
unordered_map<long, long> gcd[maxa], cnt;
map<long long, pair<vector<long>, long>> idx;
long long nums[maxn], query[maxn];
bool vis[maxn];

void init() {
    vector<bool> vis(maxa, false);
    for(long i=2;i<maxa;i++) if(!vis[i]) {
        for(long j=i;j<maxa;j+=i) {
            vis[j]=true;
            long ans = j;
            while(ans%i==0) gcd[j][i]++, ans /= i;
        }
    }
}

void dfs(long x, long y) {
    // cout<<x<<" "<<y<<endl;
    if(vis[y]) return;
    for(auto it: gcd[nums[y]]) cnt[it.first] += it.second;
    vis[y] = true;
    if(idx.find(x*maxn+y)!=idx.end()) {
        long long res = 1;
        for(auto it: cnt) {
            res = (res*(it.second+1))%mod;
        }
        idx[x*maxn+y].second = res;
    }
    for(long z: adj[y]) if(!vis[z]) dfs(x, z);
    for(auto it: gcd[nums[y]]) cnt[it.first] -= it.second;
}

long long cal(vector<long>& vec) {
    // for(long i: vec) cout<<nums[i]<<" ";
    unordered_map<long, long> cnt;
    for(long i: vec) for(auto it: gcd[nums[i]]) {
        cnt[it.first] += it.second;
    }
    long long res = 1;
    for(auto it: cnt) {
        res = (res*(it.second+1))%mod;
    }
    return res;
}

int main(){
    init();
    long long t, n, q, u, v; cin>>t;
    while(t--) {
        cin>>n;
        memset(adj, 0, sizeof(adj));
        for(long i=1;i<n;i++) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(long i=1;i<=n;i++) cin>>nums[i];
        cin>>q;
        idx.clear();
        for(long i=0;i<q;i++) {
            cin>>u>>v;
            if(u>v) swap(u, v);
            idx[u*maxn+v].first.push_back(i);
            // cout<<u<<v<<endl;
        }
        for(auto& it: idx) if(it.second.second==0) {
            cnt.clear();
            memset(vis, 0, sizeof(vis));
            dfs(it.first/maxn, it.first/maxn);
        }
        for(auto& it: idx) for(long i: it.second.first) query[i]=it.second.second;
        for(long i=0;i<q;i++) cout<<query[i]<<endl;
    }
    return 0;
}