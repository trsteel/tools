#include <iostream>

using namespace std;

const long maxn = 5001;
long dp[maxn][maxn];

int main(){
    long n, m, res = 0;
    string a, b;
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        dp[i][j] = max(max(dp[i][j-1], dp[i-1][j])-1, (a[i-1]==b[j-1]?dp[i-1][j-1]+2:0));
        res = max(res, dp[i][j]);
    }
    cout<<res<<endl;
    return 0;
}