#include <iostream>
#include <string.h>
using namespace std;
const long long maxn = 5001, mod = 1e9 + 7;
long long n, k, q, a[maxn], id, x, cnt[maxn], dp[maxn][maxn], sum;

void cal() {
    for(int i=1;i<=n;i++) dp[0][i]=1;
    for(int d=1;d<=k;d++) {
        for(int i=1;i<=n;i++) {
            dp[d][i] = (dp[d-1][i-1]+dp[d-1][i+1])%mod;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int d=0;d<=k;d++) {
            cnt[i] = (cnt[i]+dp[d][i]*dp[k-d][i]%mod)%mod;
        }
        sum = (sum + a[i]*cnt[i]%mod)%mod;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    cal();
    while(q--) {
        cin>>id>>x;
        sum = (sum-a[id]*cnt[id]%mod);
        sum = (sum + mod + x*cnt[id]%mod) % mod;
        a[id] = x;
        cout<<sum<<endl;
    }
    return 0;
}