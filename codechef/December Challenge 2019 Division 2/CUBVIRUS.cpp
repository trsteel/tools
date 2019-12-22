#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int one(vector<vector<string> >& grid, vector<int>& x, vector<int>& y, vector<int>& z) {
    int n = grid.size();
    vector<int> cnt(n, 0); 
    int res = 0;
    for(int k : z) {
        for(int i=0;i<n;i++) {
            int ans = 0;
            for(int j=0;j<n;j++) {
                if(grid[k][x[i]][y[j]]=='1') {
                    ans = n-j; break;
                }
            }
            cnt[i] = max(cnt[i], ans);
            res += cnt[i];
        }
    }
    string tmp = "";
    for(int i: x) tmp += to_string(i+1);
    for(int i: y) tmp += to_string(i+1);
    for(int i: z) tmp += to_string(i+1);
    cout<<tmp<<" "<<res<<endl;
    return res;
}

void dfs(vector<vector<string> >& grid, vector<vector<int> >& vec, 
        int k, int i, int ans, vector<vector<int> >& res) {
    
}

vector<vector<int> > cal(vector<vector<string> >& grid) {
    int n = grid.size();
    vector<vector<int> > res(3, vector<int>(n));
    for(int i=0;i<n;i++) res[0][i]=res[1][i]=res[2][i]=i;
    int ans = one(grid, res[0], res[1], res[2]);
    for(int k=0;k<3;k++) {
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(res[k][i], res[k][j]);
                int cur = one(grid, res[0], res[1], res[2]);
                if(cur < ans) ans = cur;
                else swap(res[k][i], res[k][j]);
            }
        }
    }
    return res;
}

int main(){
    int n; cin>>n;
    vector<vector<string> > grid(n, vector<string>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>grid[i][j];
        }
    }
    vector<vector<int> > vec = cal(grid);
    for(int i=0;i<vec.size();i++) {
        for(int j=0;j<vec[i].size();j++) cout<<(vec[i][j]+1)<<" ";
        cout<<endl;
    }
    return 0;
}