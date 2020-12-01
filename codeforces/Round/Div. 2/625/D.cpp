#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int main() {
    int n, m, k, u, v; cin>>n>>m;
    vector<vector<int> > adj(n+1), edge(n+1);
    while(m--) {
        cin>>u>>v;
        adj[u].push_back(v);
        edge[v].push_back(u);
    }
    cin>>k;
    vector<int> path(k);
    for (int i=0; i<k; i++) cin>>path[i];
    // 查找某个点到其他点的最短距离
    vector<int> dis(n+1, INT_MAX);
    dis[path[k-1]]=0;
    queue<int> q;
    q.push(path[k-1]);
    while (!q.empty()) {
        int a=q.front(); q.pop();
        for (int i:edge[a]) if (dis[i]>dis[a]+1) {
            dis[i]=dis[a]+1; q.push(i);
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int i=0; i<k-1; i++) {
        int mx=INT_MAX,cnt=0,id=0;
        for (int j:adj[path[i]]) {
            if (dis[j]<mx) mx=dis[j], id=j, cnt=1;
            else if (dis[j]==mx) cnt++;
        }
        if (mx<dis[path[i+1]]) ans1++, ans2++;
        else if (cnt>1) ans2++;
    }
    cout<<ans1<<" "<<ans2<<endl;
}
