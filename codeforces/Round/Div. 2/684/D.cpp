#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 100001;
vector<int> adj[maxn];
int in[maxn], vis[maxn], t, n, m, k, u, v;

bool clique(int x) {
    vector<int> vec;
    vec.push_back(x);
    for(int y: adj[x]) {
        if(vis[y] == 2) continue;
        if(in[y] < k-1) return false;
        vec.push_back(y);
    }
    for(int y: vec) for(int z: vec) {
        if(y==z) break;
        if(!binary_search(adj[y].begin(), adj[y].end(), z)) return false;
    }
    cout<<2<<endl;
    for(int y: vec) cout<<y<<" ";
    cout<<endl;
    return true;
}

void solve() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        in[i] = vis[i] = 0;
        adj[i].clear();
    }
    for(long i=0;i<m;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        in[v]++, in[u]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) {
        sort(adj[i].begin(), adj[i].end());
        if(in[i] < k) vis[i] = 1, q.push(i);
    }
    while(!q.empty()) {
        int x = q.front(); q.pop(); vis[x] = 2;
        if(in[x]==k-1&&1LL*k*(k-1)<=2*m) {
            if(clique(x)) return;
        }
        for(auto y: adj[x]) {
            if(--in[y]<k && vis[y]==0) {
                vis[y]=1; q.push(y);
            }
        }
    }
    for(int i=1;i<=n;i++) if(vis[i]==0) {
        vector<int> ans;
        for(int j=1;j<=n;j++) if(vis[j]==0) ans.push_back(j);
        cout<<1<<" "<<ans.size()<<endl;
        for(auto j: ans) cout<<j<<" ";
        cout<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main(){
    string s;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}