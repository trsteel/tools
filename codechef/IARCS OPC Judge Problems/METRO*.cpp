#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cal(int t, int station, int direct, int offset, int s, int n) {
    while(direct == 1) {
        if(t<=s+max(0, (station-1)*offset)) 
            return s + (station-1)*offset;
        s += 2*(n-1)*offset;
    }
    return cal(t, n-station+1, 1, offset, s+(n-1)*offset, n);
}

void bfs(vector<vector<int> >& row, vector<vector<int> >& col, 
        vector<vector<int> >& dp, int a, int b) {
    queue<vector<int> > q;
    q.push({a, b});
    int m = row.size()-1, n = col.size()-1;
    vector<vector<int> > direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!q.empty()) {
        auto v = q.front(); q.pop();
        for(auto& di : direct) {
            int x = v[0]+di[0], y=v[1]+di[1];
            if(x<1 || x>m || y<1 || y>n) continue;
            int d = di[0]!=0 ? (col[v[1]][0]+cal(dp[v[0]][v[1]], v[0], di[0], col[v[1]][0], col[v[1]][1], m))
                             : (row[v[0]][0]+cal(dp[v[0]][v[1]], v[1], di[1], row[v[0]][0], row[v[0]][1], n));
            if(dp[x][y]==-1||dp[x][y]>d) {
                q.push({x, y}); dp[x][y] = d;
            }
        }
    }
}

int main(){
    int m, n; cin>>m>>n;
    vector<vector<int> > row(m+1, vector<int>(2)), col(n+1, vector<int>(2));
    string s; int num;
    for(int i=1;i<=m;i++) {
        cin>>s>>row[i][1];
        row[i][0] = s=="F" ? 1 : (s=="O" ? 2 : 3);
    }
    for(int i=1;i<=n;i++) {
        cin>>s>>col[i][1];
        col[i][0] = s=="F" ? 1 : (s=="O" ? 2 : 3);
    }
    int a, b, c, d, e;
    cin>>a>>b>>c>>d>>e;
    vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
    dp[a][b] = c;
    bfs(row, col, dp, a, b);
    cout<<dp[d][e]<<endl;
    return 0;
}