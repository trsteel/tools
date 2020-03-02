#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int cal(vector<string>& grid, int k) {
    int n = grid.size();
    vector<int> vis(n, INT_MAX);
    queue<int> q;
    q.push(0);
    vis[0] = 0;
    while(!q.empty()) {
        int i = q.front(); q.pop();
        for(int j=i-k; j<=i+k; j++) {
            if(j>=0 && j<n && grid[i][j]=='1' && vis[i]+1<vis[j]) {
                q.push(j); vis[j] = vis[i]+1;
            }
        }
    }
    return vis[n-1]==INT_MAX?-1:vis[n-1];
}

int main(){
    int t, n, k; cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<string> grid(n);
        for(int i=0;i<n;i++) cin>>grid[i];
        cout<<cal(grid, k)<<endl;
    }
    return 0;
}