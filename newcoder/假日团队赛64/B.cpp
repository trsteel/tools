#include <iostream>
#include <string.h>
using namespace std;
long n, m;
string g[16];
long cache[16*16];

long dfs(long p) {
    if(p==m*n-1) return 1;
    if(cache[p] != -1) return cache[p];
    long x = p/m, y = p%m, res = 0;
    // cout<<p<<" "<<x<<" "<<y<<endl;
    for(int i=x+1;i<n;i++) {
        for(int j=y+1;j<m;j++) {
            if(g[x][y]!=g[i][j]) res+=dfs(i*m+j);
        }
    }
    return cache[p] = res;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>g[i];
    memset(cache, -1, sizeof(cache));
    cout<<dfs(0)<<endl;
    return 0;
}