#include <iostream>

using namespace std;

long t, n, m, sum[502][502];
char a[501][501];

long find(int x, int y) {
    if(a[x][y] == '.') return 0;
    long res = 0;
    long l = y, r = y;
    while(l>=0 && r < m && x < n) {
        long d = sum[x][r+1] - sum[x][l];
        if(d != r-l+1) break;
        res++, x++, l--, r++;
    }
    // cout<<x<<" "<<y<<" "<<res<<endl;
    return res;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            sum[i][0] = 0;
            for(int j=0;j<m;j++) {
                cin>>a[i][j];
                sum[i][j+1] = a[i][j]=='*'?(sum[i][j]+1):0;
            }
        }
        long res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) res += find(i, j);
        }
        cout<<res<<endl;
    }
    return 0;
}