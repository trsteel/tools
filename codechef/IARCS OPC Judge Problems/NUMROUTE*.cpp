#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void cal(vector<vector<int> >& a, vector<vector<int> >& b) {
    long n = a.size(), mod = 42373;
    vector<vector<int> > c(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        for(int k=0;k<n;k++) {
            c[i][j] = (c[i][j]+(long)a[i][k]*b[k][j])%mod;
        }
    }
    a = move(c);
}

int main(){
    int n; cin>>n;
    vector<vector<int> > grid(n, vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        cin>>grid[i][j];
    }
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) dp[i][i] = 1;
    int s, t, k; cin>>s>>t>>k;
    while(k) {
        if(k&1) cal(dp, grid);
        k >>= 1;
        cal(grid, grid);
    }
    cout<<dp[s-1][t-1]<<endl;
    return 0;
}