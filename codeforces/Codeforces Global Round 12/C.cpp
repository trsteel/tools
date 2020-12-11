#include <iostream>

using namespace std;
long t, n,cnt[3];
char dp[301][301][3];
string grid[301];

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>grid[i];
        for(int k=0;k<3;k++) {
            cnt[k] = 0;
            for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
                dp[i][j][k] = grid[i][j];
                if((i+j+2)%3==k && dp[i][j][k]=='X') {
                    dp[i][j][k] = 'O', cnt[k]++;
                } else if((i+j)%3==k && dp[i][j][k]=='O') {
                    dp[i][j][k] = 'X', cnt[k]++;
                }
            }
        }
        long ans = 0;
        for(int i=0;i<3;i++) if(cnt[ans] > cnt[i]) ans = i;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<dp[i][j][ans];
            cout<<endl;
        }

    }
    return 0;
}