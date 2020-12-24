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
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
            res += dp[i][a[j]]*(dp[n][a[i]]-dp[j+1][a[i]]);
        }
        cout<<res<<endl;
    }
    return 0;
}