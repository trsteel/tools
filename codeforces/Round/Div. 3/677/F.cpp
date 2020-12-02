#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n, m, k, a[71][71];
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
    vector<long> dp(k, 0);
    for(int i=0;i<n;i++) {
        vector<vector<long>> tmp(k, vector<long>(m/2+1, 0));
        for(int j=0;j<m;j++) {
            vector<vector<long>> tmp2 = tmp;
            for(int o=0;o<k;o++) for(int l=0;l<m/2;l++) {
                if(tmp[o][l]%k==o) {
                    long ans = (o+a[i][j])%k;
                    tmp2[ans][l+1] = max(tmp2[ans][l+1], tmp[o][l] + a[i][j]);
                }
            }
            tmp = move(tmp2);
        }
//        for(int o=0;o<k;o++) {
//            for(int l=0;l<=m/2;l++) cout<<tmp[o][l]<<" ";
//            cout<<endl;
//        }
        vector<long> dp2 = dp;
        for(int j=0;j<k;j++) {
            for(int o=0;o<k;o++) for(int l=0;l<=m/2;l++) if(tmp[o][l]%k==o && dp[j]%k==j) {
                dp2[(o+j)%k] = max(dp2[(o+j)%k], dp[j] + tmp[o][l]);
            }
        }
        dp = move(dp2);
//        cout<<i<<" ";
//        for(int j=0;j<k;j++) cout<<dp[j]<<" ";
//        cout<<endl;
    }
    cout<<dp[0]<<endl;
    return 0;
}
