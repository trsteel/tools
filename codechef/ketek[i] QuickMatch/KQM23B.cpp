#include <iostream>
#include <vector>
using namespace std;

bool find(vector<string>& grid, string& s, int i, int j, int k, int dx, int dy) {
    // cout<<s<<" "<<i<<" "<<j<<" "<<k<<" "<<dx<<" "<<dy<<endl;
    if(i<0||i>=grid.size()||j<0||j>=grid[i].size()) return false;
    if(grid[i][j]!=s[k]) return false;
    return k+1==s.size() || find(grid, s, i+dx, j+dy, k+1, dx, dy);
}

bool find(vector<string>& grid, string& s) {
    for(int i=0;i<grid.size();i++) for(int j=0;j<grid[i].size();j++) {
        if(grid[i][j]!=s[0]) continue;
        for(int dx=-1; dx<=1; dx++) for(int dy=-1; dy<=1; dy++) {
            if(dx==0 && dy==0) continue;
            if(find(grid, s, i, j, 0, dx, dy)) return true;
        }
    }
    return false;
}

int main(){
    int n, r, c; cin>>n;
    vector<string> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cin>>r>>c;
    vector<string> grid(r);
    for(int i=0;i<r;i++) cin>>grid[i];
    int res = 0;
    for(string& s: vec) {
        if(find(grid, s)) res++;
    }
    cout<<res<<endl;
    return 0;
}