#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
bool match(vector<vector<int> >& num, int x, int y, int len) {
    int ans = 0; for(int i=0;i<len;i++) ans+=num[x+i][y];
    // cout<<x<<y<<len<<ans<<endl;
    for(int i=0;i<len;i++) {
        int row=0, col=0;
        for(int j=0;j<len;j++){
            row += num[x+i][y+j];
            col += num[x+j][y+i];
        }
        if(row!=ans || col!=ans) return false;
    }
    int tmp=0; for(int i=0;i<len;i++) tmp+=num[x+i][y+i];
    if(tmp != ans) return false;
    tmp=0; for(int i=0;i<len;i++) tmp+=num[x+i][y+len-i-1];
    if(tmp != ans) return false;
    return true;
}
int main() {
    int n;
    cin>>n;
    vector<vector<int> > num(n, vector<int>(n, 0));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>num[i][j];
    long res = n*n;
    for(int len=2;len<=n;len++) {
        for(int i=0;i<=n-len;i++) {
            for(int j=0;j<=n-len;j++) {
                if(match(num, i, j, len)) res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}