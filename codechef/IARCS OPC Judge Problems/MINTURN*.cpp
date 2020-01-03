#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main(){
    int m,n; cin>>m>>n;
    vector<vector<vector<char> > > grid(m, 
        vector<vector<char> >(n, vector<char>(4)));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
        for(int k=0;k<4;k++) cin>>grid[i][j][k];
    }
    vector<vector<pair<int, int> > > ans(m*n);
    vector<vector<int> > dir = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<vector<int> > step = {{2,1,0,3},{3,2,1,0},{0,3,2,1},{1,0,3,2}};
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
        for(int d=0;d<4;d++) {
            int x = i+dir[d][0], y = j+dir[d][1];
            if(x<0||x>=m||y<0||y>=n) continue;
            for(int k=0;k<4;k++) {
                if(grid[i][j][k]!=grid[x][y][d]) {
                    ans[i*n+j].push_back({step[d][k], x*n+y});
                }
            }
        }
    }
    priority_queue<pair<int, int> > pq;
    pq.push({0, 0});
    vector<int> dp(n*m, INT_MAX);
    vector<bool> vis(n*m, false);
    dp[0] = 0;
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();
        // cout<<p.first<<" "<<p.second<<endl;
        if(vis[p.second]) continue;
        vis[p.second] = true;
        dp[p.second] = -p.first;
        for(auto& pi : ans[p.second]) {
            if(!vis[pi.second] && dp[p.second]+pi.first<dp[pi.second]) {
                pq.push({-(dp[p.second]+pi.first), pi.second});
            }
        }
    }
    cout<<dp[m*n-1]<<endl;
    return 0;
}