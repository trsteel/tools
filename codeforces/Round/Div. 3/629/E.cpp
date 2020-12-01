#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const long maxn = 200001;
vector<long> adj[maxn];
long in[maxn], out[maxn], parent[maxn], cnt = 0;

void dfs(long u, long p) {
    parent[u] = p, in[u] = ++cnt;
    for(long v: adj[u]) if(v!=p) dfs(v, u);
    out[u] = cnt;
}

int main(){
    long m, n, x, y, k;
    cin>>n>>m;
    for(long i=1;i<n;i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    while(m--) {
        cin>>k;
        long ma=1, mi=n;
        while(k--) {
            cin>>x;
            if(x!=1) x = parent[x];
            ma = max(ma, in[x]);
            mi = min(mi, out[x]);
        }
        cout<<(ma<=mi?"YES":"NO")<<endl;
    }
    return 0;
}