#include <iostream>
#include <string.h>
using namespace std;
const long maxn = 3001;
long t, n, a[3001], dp[maxn][maxn];

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<n;i++) {
            cin>>a[i];
            for(int j=1;j<=n;j++) {
                dp[i+1][j] = dp[i][j] + (a[i]==j?1:0);
            }
        }
        long long res = 0;
        for(int i=0;i<n;i++) for(int j=i+2;j<n;j++) {
            if(a[i] != a[j]) continue;
            for(int k=1;k<=n;k++) {
                res += (dp[j][k]-dp[i+1][k])*(dp[n][k]-dp[j+1][k]);
            }
            // cout<<i<<" "<<j<<" "<<res<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}