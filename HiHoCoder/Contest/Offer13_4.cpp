//TLE 30%

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,r,c;
    cin>>n>>r>>c;
    vector<vector<vector<long>>> dp(n,vector<vector<long>>(12,vector<long>(12,0)));
    for(int i=2;i<10;i++){
        for(int j=2;j<10;j++){
            dp[0][i][j]=1;
        }
    }
    for(int k=1;k<n;k++){
        for(int i=2;i<10;i++){
            for(int j=2;j<10;j++){
                dp[k][i][j]=(dp[k-1][i-2][j-1]+dp[k-1][i-2][j+1]+dp[k-1][i+2][j-1]+dp[k-1][i+2][j+1]+dp[k-1][i-1][j-2]+dp[k-1][i-1][j+2]+dp[k-1][i+1][j-2]+dp[k-1][i+1][j+2])%1000000007;
            }
        }
    }
    int ans = (dp[n-1][r-1][c]+dp[n-1][r-1][c+2]+dp[n-1][r+3][c]+dp[n-1][r+3][c+2]+dp[n-1][r][c-1]+dp[n-1][r][c+3]+dp[n-1][r+2][c-1]+dp[n-1][r+2][c+3])%1000000007;
    cout<<ans<<endl;
    return 0;
}
