#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(vector<vector<bool> >& grid, vector<int>& sub, vector<bool>& vis, int k, int i) {
    vis[i] = true;
    for(int j = 0;j<grid.size(); j++) {
        if(!vis[j] && grid[i][j]) {
            if(--sub[j]<k) dfs(grid, sub, vis, k, j);
        }
    }
}

int cal(vector<vector<bool> >& grid, vector<int>& sub, int k) {
    int n = grid.size();
    vector<bool> vis(n, false);
    bool changed = true;
    while(changed) {
        changed = false;
        for(int i=0;i<n;i++) {
            if(!vis[i] && sub[i]<k) {
                dfs(grid, sub, vis, k, i);
                changed = true;
            }
        }
    }
    int res = 0;
    for(bool b: vis) if(!b) res++;
    return res;
}

int main(){
    int m, n, k; cin>>n>>m>>k;
    vector<vector<bool> > grid(n, vector<bool>(n, false));
    vector<int> sub(n, 0);
    int i, j;
    while(m--) {
        cin>>i>>j;
        grid[i-1][j-1] = grid[j-1][i-1] = true;
        sub[i-1]++;
        sub[j-1]++;
    }
    auto res = cal(grid, sub, k);
    cout<<(res>0?"YES":"NO")<<endl;
    if(res>0) cout<<res<<endl;
    return 0;
}