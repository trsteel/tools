#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
    long long n, u, v; cin>>n;
    vector<vector<long long> > adj(n+1);
    vector<long long> in(n+1, 0);
    unordered_map<long long, long> um;
    for(int i=0;i<n-1;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++in[u], ++in[v];
        um[u*n+v]=um[v*n+u]=i;
    }
    queue<long long> q;
    for(int i=1;i<=n;i++) if(in[i]==1) q.push(i);
    long ans = 0;
    vector<long> res(n-1);
    vector<bool> vis(n+1, false);
    while(!q.empty()) {
        u = q.front(); q.pop();
        vis[u] = true;
        for(long v: adj[u]) {
            if(vis[v]) continue;
            res[um[u*n+v]] = ans++;
            if(--in[v]==1) q.push(v);
        }
    }
    for(long i: res) cout<<i<<endl;
    return 0;
}