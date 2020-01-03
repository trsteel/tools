#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& grid, vector<vector<bool> >& parent,
        vector<int>& vec, vector<int>& dp, int i, int pre) {
    dp[i] = vec[i];
    parent[i][i] = true;
    for(int j: grid[i]) {
        if(j==pre) continue;
        dfs(grid, parent, vec, dp, j, i);
        dp[i] += dp[j];
        for(int k=1;k<vec.size();k++) {
            if(parent[j][k]) parent[i][k] = true;
        }
    }
}

int cal(vector<int>& vec, vector<vector<int> >& grid) {
    int n = grid.size();
    vector<int> dp(n, 0);
    vector<vector<bool> > parent(n, vector<bool>(n, false));
    dfs(grid, parent, vec, dp, 1, 0);
    int res = 1<<30;
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            if(parent[i][j]) {
                res = min(res, max(dp[j], max(dp[i] - dp[j], dp[1] - dp[i])));
            } else if(!parent[j][i]) {
                res = min(res, max(dp[j], max(dp[i], dp[1] - dp[i] - dp[j])));
            }
        }
    }
    return res;
}

int main(){
    int n; cin>>n;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++) cin>>vec[i];
    vector<vector<int> > grid(n+1);
    int a, b;
    for(int i=0;i<n-1;i++) {
        cin>>a>>b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    cout<<cal(vec, grid)<<endl;
    return 0;
}