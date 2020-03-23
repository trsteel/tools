
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn = 500001;
int match[maxn];
bool check[maxn];
vector<int> adj[maxn];

bool dfs(int u) {
    for(int v: adj[u]) if (!check[v]) {
        check[v] = true;
        if(match[v]==-1||dfs(match[v])) {
            match[v] = u, match[u] = v;
            return true;
        }
    }
    return false;
}

int main(){
    long n, m, x, y; cin>>n>>m;
    map<pair<int, int>, int> idx;
    for(int i=1;i<=m;i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if(x>y) swap(x, y);
        idx[make_pair(x, y)] = i;
    }
    // 最大二分匹配
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int i=1;i<=n;i++) if(match[i]==-1) {
        memset(check, 0, sizeof(check));
        if(dfs(i)) ans++;
    }
    // cout<<n<<ans<<endl;
    if(ans<n-1) {cout<<-1<<endl; return 0; }
    vector<int> res;
    for(int i=1;i<=n;i++) {
        if(match[i]>i) res.push_back(idx[make_pair(i, match[i])]);
    }
    sort(res.begin(), res.end());
    cout<<res.size()<<endl;
    for(int i: res) cout<<i<<endl;
    return 0;
}