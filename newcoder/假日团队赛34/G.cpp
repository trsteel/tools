/**
 * 并查集+贪心
 **/
#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int maxn = 50001;

vector<unordered_set<int> > adj;
int parent[maxn], color[maxn];

int find(int x) {
    if(parent[x]==0||parent[x]==x) return parent[x] = x;
    return parent[x] = find(parent[x]);
}

bool dfs(int u, int c) {
    if(color[u]==-1) color[u] = c;
    if(color[u]!=c) return false;
    c ^= 1;
    for(int v: adj[u]) if(color[v]!=c && !dfs(v, c)) return false;
    return true;
}

int main(){
    int n, m; cin>>n>>m;
    int u, v, a, b;
    adj.clear();
    adj.resize(n+1);
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        a = find(u), b = find(v);
        if(a!=b) parent[a] = b;
    }
    unordered_map<int, vector<int> > um;
    for(int i=1;i<=n;i++) um[find(i)].push_back(i);
    memset(color, -1, sizeof(color));
    long res = 0, ans;
    for(auto& it: um) {
        if(!dfs(it.first, 0)) {
            cout<<-1<<endl; return 0;
        }
        ans = 0;
        for(int i: it.second) ans += color[i];
        res += max(ans, long(it.second.size()-ans));
    }
    cout<<res<<endl;
    return 0;
}