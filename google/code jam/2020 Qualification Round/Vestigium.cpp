#include <iostream>
#include <string.h>
using namespace std;

const long maxn = 101;
long long grid[maxn][maxn];
bool rows[maxn][maxn], rvis[maxn], cols[maxn][maxn], cvis[maxn];

int main(){
    long long T, n; cin>>T;
    for(long long t=1;t<=T;t++) {
        cin>>n;
        for(long i=0;i<n;i++) for(long j=0;j<n;j++) cin>>grid[i][j];
        memset(rows, 0, sizeof(rows));
        memset(rvis, 0, sizeof(rvis));
        memset(cols, 0, sizeof(cols));
        memset(cvis, 0, sizeof(cvis));
        long long k = 0, r = 0, c = 0;
        for(long i=0;i<n;i++) for(long j=0;j<n;j++) {
            if(rows[i][grid[i][j]] && !rvis[i]) {
                r++, rvis[i] = true;
            }
            if(cols[j][grid[i][j]] && !cvis[j]) {
                c++, cvis[j] = true;
            }
            if(i==j) k+=grid[i][j];
            rows[i][grid[i][j]] = cols[j][grid[i][j]] = true;
        }
        cout<<"Case #"<<t<<": "<<k<<" "<<r<<" "<<c<<endl;
    }
    return 0;
}