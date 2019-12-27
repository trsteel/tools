#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cal(vector<vector<bool> >& grid, int start, int end) {
    int n = grid.size();
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(start);
    int step = 0;
    while(!q.empty()) {
        int t = q.size();
        while(t--) {
            int x = q.front(); q.pop();
            if(x==end) return step;
            if(vis[x]) continue;
            vis[x] = true;
            for(int i=0;i<n;i++) {
                if(!vis[i] && grid[x][i]) q.push(i); 
            }
        }
        step++;
    }
    return 0;
}

int main(){
    int n, m; cin>>n>>m;
    vector<vector<bool> > grid(n, vector<bool>(n, false));
    int a, b;
    while(m--) {
        cin>>a>>b;
        grid[a-1][b-1] = grid[b-1][a-1] = true;
    }
    cin>>a>>b;
    cout<<cal(grid, a-1, b-1)<<endl;
    return 0;
}