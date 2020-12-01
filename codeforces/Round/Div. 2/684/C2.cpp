#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int maxn = 101;
bool grid[maxn][maxn];

void cal(vector<vector<int> >& res, int x1, int y1, int x2, int y2, int x3, int y3) {
    grid[x1][y1] = !grid[x1][y1];
    grid[x2][y2] = !grid[x2][y2];
    grid[x3][y3] = !grid[x3][y3];
    res.push_back({x1, y1, x2, y2, x3, y3});
}

void solve(vector<vector<int> >& res, int n, int m) {
    for(int i=1;i<n-1;i++) for(int j=1;j<m;j++) {
        if(grid[i-1][j-1] && grid[i-1][j]) {
            cal(res, i-1, j-1, i-1, j, i, j-1);
        } else if(grid[i-1][j-1]) {
            cal(res, i-1, j-1, i, j-1, i, j);
        } else if(grid[i-1][j]) {
            cal(res, i-1, j, i, j-1, i, j);
        }
    }
    for(int j=1;j<m;j++) {
        if(grid[n-2][j-1]&&grid[n-1][j-1]) {
            cal(res, n-2, j-1, n-1, j-1, n-1, j);
        } else if(grid[n-2][j-1]) {
            cal(res, n-2, j-1, n-2, j, n-1, j);
        } else if(grid[n-1][j-1]) {
            cal(res, n-1, j-1, n-2, j, n-1, j);
        }
    }
    if(grid[n-1][m-1] && grid[n-2][m-1]) {
        cal(res, n-1, m-1, n-1, m-2, n-2, m-2);
        cal(res, n-1, m-2, n-2, m-2, n-2, m-1);
    } else if(grid[n-1][m-1]) {
        cal(res, n-1, m-1, n-1, m-2, n-2, m-1);
        cal(res, n-2, m-2, n-1, m-1, n-2, m-1);
        cal(res, n-1, m-1, n-2, m-2, n-1, m-2);
    } else if(grid[n-2][m-1]) {
        cal(res, n-2, m-1, n-2, m-2, n-1, m-1);
        cal(res, n-1, m-1, n-2, m-1, n-1, m-2);
        cal(res, n-2, m-2, n-1, m-2, n-2, m-1);
    }
}

int main(){
    int t, n, m;
    string s;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            cin>>s;
            for(int j=0;j<m;j++) {
                grid[i][j] = s[j]=='1';
            }
        }
        vector<vector<int> > res;
        solve(res, n, m);
        cout<<res.size()<<endl;
        for(auto& v: res) {
            for(int i: v) cout<<(i+1)<<" ";
            cout<<endl;
        }
    }
    return 0;
}