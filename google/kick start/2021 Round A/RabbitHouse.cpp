#include <iostream>
using namespace std;

long grid[1001][1001], r, c;

long change(int i, int j) {
    long res = 0;
    if(i>0 && grid[i-1][j]+1<grid[i][j]) {
        res += grid[i][j]-1-grid[i-1][j];
        grid[i-1][j] = grid[i][j]-1;
        res += change(i-1, j);
    }
    if(i<r-1 && grid[i+1][j]+1<grid[i][j]) {
        res += grid[i][j]-1-grid[i+1][j];
        grid[i+1][j] = grid[i][j]-1;
        res += change(i+1, j);
    }
    if(j>0 && grid[i][j-1]+1<grid[i][j]) {
        res += grid[i][j]-1-grid[i][j-1];
        grid[i][j-1] = grid[i][j]-1;
        res += change(i, j-1);
    }
    if(j<c-1 && grid[i][j+1]+1<grid[i][j]) {
        res += grid[i][j]-1-grid[i][j+1];
        grid[i][j+1] = grid[i][j]-1;
        res += change(i, j+1);
    }
    return res;
}

long cal() {
    long res = 0;
    for(long i=0;i<r;i++) for(long j=0;j<c;j++) {
        res += change(i, j);
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