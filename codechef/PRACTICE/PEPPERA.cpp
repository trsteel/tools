#include <iostream>
#include <vector>

using namespace std;

string process(vector<vector<int> >& num, int sum) {
    int n = num.size();
    vector<vector<string> > dp(n, vector<string>(sum+1, ""));
    for(int i=0;i<num[0].size();i++) dp[0][num[0][i]] = to_string(i);
    for(int i=1;i<n;i++) for(int j=0;j<=sum;j++) {
        if(dp[i-1][j].empty()) continue;
        for(int k=0;k<num[i].size();k++) dp[i][j+num[i][k]]=dp[i-1][j]+to_string(k);
    }
    for(int i=sum/2;i>=0;i--) {
        if(!dp[n-1][i].empty()) return dp[n-1][i];
    }
    return "";
}

void cal(vector<string>& grid) {
    int n = grid.size(), sum=0;
    vector<vector<int> > num(n, vector<int>(2, 0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        sum += grid[i][j]-'0';
        num[i][j<n/2?0:1] += grid[i][j]-'0';
    }
    string ans = process(num, sum);
    for(int i=0;i<ans.size();i++) {
        if(ans[i]=='0') continue;
        for(int j=0;j<n/2;j++) swap(grid[i][j], grid[i][n-1-j]);
    }
}

int main(){
    int t, n; cin>>t;
    string s;
    while(t--) {
        cin>>n;
        vector<string> grid(n);
        for(int i=0;i<n;i++) cin>>grid[i];
        cal(grid);
        for(int i=0;i<n;i++) cout<<grid[i]<<endl;
    }
    return 0;
}