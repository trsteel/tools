#include <iostream>
#include <algorithm>
using namespace std;
const long maxn = 201;
long long r, g, b, rr[maxn], gg[maxn], bb[maxn], dp[maxn+2][maxn+2][maxn+2];

int main(){
    cin>>r>>g>>b;
    for(int i=0;i<r;i++) cin>>rr[i];
    for(int i=0;i<g;i++) cin>>gg[i];
    for(int i=0;i<b;i++) cin>>bb[i];
    sort(rr, rr+r), sort(gg, gg+g), sort(bb, bb+b);
    long long ans = 0;
    for(int i=r;i>=0;i--) for(int j=g;j>=0;j--) {
        for(int k=b;k>=0;k--) {
            dp[i][j][k] = max(dp[i+1][j+1][k]+rr[i]*gg[j],max(dp[i+1][j][k+1]+rr[i]*bb[k],max(dp[i][j+1][k+1]+gg[j]*bb[k],0LL)));
            ans = max(dp[i][j][k], ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}