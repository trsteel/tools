//TLE 40%

#include <iostream>
#include <vector>
using namespace std;
int findMax(vector<vector<int>> dp, int n,int m, int k,int x,int y, int maxLen){
    for(int i=x;i<n;i++){
        for(int j=y;j<m;j++){
            if((i-x+1)*(j-y+1)>maxLen &&
               (dp[i+1][j+1]+dp[x][y]-dp[i+1][y]-dp[x][j+1])<=k){
                maxLen=(i-x+1)*(j-y+1);
                //cout<<x<<" "<<y<<" "<<i<<" "<<j<<endl;
            }
        }
    }
    return maxLen;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> a(n,vector<int>(m,0));
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i][j-1];
            for(int k=0;k<i;k++){
                dp[i][j]+=a[k][j-1];
            }
        }
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = findMax(dp,n,m,k,i,j,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}
