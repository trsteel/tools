/**
 * 关键点: 带路径的dp
 **/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void cal(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    map<vector<int>, vector<int> > parent;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        for(int k=0;k<i;k++) for(int l=0;l<j;l++) {
            if(a[k]-a[i]==b[l]-b[j] && dp[k][l]+1>dp[i][j]) {
                dp[i][j] = dp[k][l]+1;
                parent[{i, j}] = {k, l};
            }
        }
    }
    int x=0, y=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        if(dp[x][y] < dp[i][j]) { x=i, y=j; }
    }
    cout<<dp[x][y]+1<<endl;
    vector<int> ra, rb;
    while(x>=0 && y>=0) {
        ra.push_back(a[x]);
        rb.push_back(b[y]);
        auto p = parent.find({x, y});
        if(p==parent.end()) break;
        x = p->second[0], y=p->second[1];
    }
    for(int i=ra.size()-1;i>=0;i--) cout<<ra[i]<<" ";
    cout<<endl;
    for(int i=rb.size()-1;i>=0;i--) cout<<rb[i]<<" ";
}

int main(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    cal(a, b);
    return 0;
}