#include <iostream>
using namespace std;

long grid[1001][1001], r, c;
long lf[1001][1001], rg[1001][1001], up[1001][1001], dn[1001][1001];

void init() {
    for(long i=0;i<r;i++) {
        long ans = 0;
        for(long j=c-1;j>=0;j--) {
            if(grid[i][j]==0) ans = 0;
            else ans++;
            rg[i][j] = ans;
        }
        ans = 0;
        for(long j=0;j<c;j++) {
            if(grid[i][j]==0) ans = 0;
            else ans++;
            lf[i][j] = ans;
        }
    }
    for(long j=0;j<c;j++) {
        long ans = 0;
        for(long i=r-1;i>=0;i--) {
            if(grid[i][j]==0) ans = 0;
            else ans++;
            dn[i][j] = ans;
        }
        ans = 0;
        for(long i=0;i<r;i++) {
            if(grid[i][j]==0) ans = 0;
            else ans++;
            up[i][j] = ans;
        }
    }
}

long cal(long x, long y) {
    return max(min(x/2, y)-1, 0L) + max(min(x, y/2)-1, 0L);
}

long find(long i, long j) {
    if(grid[i][j]==0) return 0;
    long res = 0;
    res += cal(up[i][j], lf[i][j]);
    res += cal(up[i][j], rg[i][j]);
    res += cal(dn[i][j], lf[i][j]);
    res += cal(dn[i][j], rg[i][j]);
    return res;
}

long cal() {
    init();
    long res = 0;
    for(long i=0;i<r;i++) for(long j=0;j<c;j++) {
        res += find(i, j);
    }
    return res;
}

int main(){
    long t; cin>>t;
    for(long tt=1;tt<=t;tt++) {
        cin>>r>>c;
        for(long i=0;i<r;i++) for(long j=0;j<c;j++) {
            cin>>grid[i][j];
        }
        long res = cal();
        cout<<"Case #"<<tt<<": "<<res<<endl;
    }
    return 0;
}