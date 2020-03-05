#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void cal(vector<vector<int> >& grid, int n, int m) {
    queue<pair<int, int> > q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(grid[i][j]==0) q.push(make_pair(i, j));
    }
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        // cout<<p.first<<" "<<p.second<<endl;
        for(int i=0;i<4;i++) {
            int x = p.first+direct[i][0], y = p.second+direct[i][1];
            if(x<0||x>=n||y<0||y>=m||grid[x][y]==-2) continue;
            if(grid[x][y]==-1||grid[x][y]>grid[p.first][p.second]+1) {
                grid[x][y]=grid[p.first][p.second]+1; q.push(make_pair(x, y));
            }
        }
    }
}

int main(){
    int t, n, m, k, x, y; cin>>t;
    while(t--) {
        cin>>n>>m;
        vector<vector<int> > grid(n, vector<int>(m, -1));
        cin>>k; while(k--) { cin>>x>>y; grid[x-1][y-1]=0; }
        cin>>k; while(k--) { cin>>x>>y; grid[x-1][y-1]=-2; }
        cal(grid, n, m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<(grid[i][j]==-2?"X":to_string(grid[i][j]))<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}