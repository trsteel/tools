#include <iostream>
#include <vector>
using namespace std;

int cal(vector<vector<int> >& grid, int x, int y) {
    int m = grid.size(), n = grid[0].size(), k = 0;
    while(true) {
        int u = x-k, d = x+k, l = y-k, r = y+k;
        if(u<0||d>=m||l<0||r>=n) break;
        if(grid[u][y]!=grid[d][y] || grid[x][l]!=grid[x][r]) break;
        k++;
    }
    return k;
}

int cal(vector<vector<int> >& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
        res += cal(grid, i, j);
    }
    return res;
}

int main(){
    int t; cin>>t;
    while(t--) {
        int m, n; cin>>m>>n;
        vector<vector<int> > grid(m, vector<int>(n));
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
            cin>>grid[i][j];
        }
        cout<<cal(grid)<<endl;
    }
    return 0;
}