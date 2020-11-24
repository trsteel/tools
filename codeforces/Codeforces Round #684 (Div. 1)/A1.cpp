#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int> >& res, vector<string>& grid, int n, int m) {
    for(int x=0;x<n;x++) for(int y=0;y<m;y++) if(grid[x][y]=='1'){
        int dx = x>0?-1:1, dy = y>0?-1:1;
        res.push_back({x, y, x+dx, y, x+dx, y+dy});
        res.push_back({x, y, x, y+dy, x+dx, y+dy});
        res.push_back({x, y, x+dx, y, x, y+dy});
    }
}

int main(){
    int t, n, m;
    cin>>t;
    vector<string> grid(101);
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>grid[i];
        vector<vector<int> > res;
        solve(res, grid, n, m);
        cout<<res.size()<<endl;
        for(auto& v: res) {
            for(int i: v) cout<<(i+1)<<" ";
            cout<<endl;
        }
    }
    return 0;
}