#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const long maxn = 1001;
vector<pair<int, int>> edges, vec;
vector<pair<int, int>> adj[maxn];
int dis[maxn][maxn],vis[maxn];

void dijkstra(int u) {
    memset(dis[u], 0x3f, sizeof(dis[u]));
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int,int>> q;
    dis[u][u] = 0;
    q.push({0, u});
    while(!q.empty()) {
        int v = q.top().second; q.pop();
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto& p: adj[v]) {
            int x = p.first, y = p.second;
            if(dis[u][x] > dis[u][v]+y) {
                dis[u][x] = dis[u][v]+y;
                q.push({-dis[u][x], x});
            }
        }
    }
}

int main() {
    long n, m, k, x, y, w;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++) {
        cin>>x>>y>>w;
        edges.push_back({x, y});
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    for(int i=0;i<k;i++) {
        cin>>x>>y;
        vec.push_back({x, y});
    }
    for(int i=1;i<=n;i++) dijkstra(i);
    long long res = 0;
    for(auto& p: vec) res += dis[p.first][p.second];
    for(auto& e: edges) {
        int X = e.first, Y = e.second;
        long long ans = 0;
        for(auto& p: vec) {
            int x = p.first, y = p.second;
            ans += min(dis[x][y], min(dis[x][X]+dis[Y][y], dis[x][Y]+dis[X][y]));
        }
        res = min(res, ans);
    }
    cout<<res<<endl;
    return 0;
}
