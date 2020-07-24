#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

double dp[2][100001];
long w, h, l, u, r, d;

bool is_hole(long x, long y) {
    return y>=l&&y<=r&&x>=u&&x<=d;
}

double cal() {
    memset(dp, 0, sizeof(dp));
    if(0==l&&0==u) return 0;
    int idx = 0;
    dp[idx][1] = 1;
    for(long i=2;i<=w;i++) {
        dp[idx][i] = dp[idx][i-1]/2;
        if(h==1) dp[idx][i] += dp[idx][i-1]/2;
        if(is_hole(1, i)) break;
    }
    for(long i=2;i<=h;i++) {
        idx ^= 1;
        for(long j=1;j<=w;j++) {
            dp[idx][j] = 0;
            if(!is_hole(i-1, j)) {
                dp[idx][j] += dp[idx^1][j]/2;
                if(j==w) dp[idx][j] += dp[idx^1][j]/2;
            }
            if(j>1 && !is_hole(i, j-1)) {
                dp[idx][j] += dp[idx][j-1]/2;
                if(i==h) dp[idx][j] += dp[idx][j-1]/2;
            }
        }
    }
    // for(long i=1;i<=h;i++) {
    //     for(long j=1;j<=w;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return dp[idx][w];
}

int main(){
    long t; cin>>t;
    for(long tt=1;tt<=t;tt++) {
        cin>>w>>h>>l>>u>>r>>d;
        cout<<"Case #"<<tt<<": "<<cal()<<endl;
    }
    return 0;
}