#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const long maxn = 100001;
long t, n, m, p[maxn], h[maxn], x, y, tree[maxn][2];
vector<long> adj[maxn];

bool dfs(long u, long pre) {
    tree[u][0] = p[u];
    long poss = 0;
    for(long v: adj[u]) {
        if(v==pre) continue;
        if(!dfs(v, u)) return false;
        tree[u][0] += tree[v][0];
        poss += tree[v][1];
    }
    long d = tree[u][0] - h[u];
    // cout<<u<<" "<<tree[u][0]<<" "<<h[u]<<endl;
    if(d < 0 || (d&1)) return false;
    tree[u][1] = d/2+h[u];
    // cout<<u<<" "<<tree[u][1]<<" "<<poss<<endl;
    return tree[u][1] >= poss;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<=n;i++) {
            adj[i].clear();
            tree[i][0]=tree[i][1]=0;
        }
        for(int i=1;i<=n;i++) cin>>p[i];
        for(int i=1;i<=n;i++) cin>>h[i];
        for(int i=1;i<n;i++) {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cout<<(dfs(1, -1)?"YES":"NO")<<endl;
    }
    return 0;
}