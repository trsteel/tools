/**
 * Time limit exceeded on test 5
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;

int main(){
    long long n, m, p, x, y, z; cin>>n>>m>>p;
    long long size = 1e6+2;
    vector<long long> a(size, INT_MAX), b(size, INT_MAX);
    for(int i=0;i<n;i++) {cin>>x>>y; a[x]=min(a[x], y);}
    for(int i=0;i<m;i++) {cin>>x>>y; b[x]=min(b[x], y);}
    for(int i=size-2;i>=0;i--) a[i] = min(a[i], a[i+1]);
    for(int i=size-2;i>=0;i--) b[i] = min(b[i], b[i+1]);
    vector<unordered_map<int, long long> > c(size);
    for(int i=0;i<p;i++) { cin>>x>>y>>z; c[x][y]+=z; }
    vector<int> pre(size, 0), cur(size, 0);
    long long res = INT_MIN;
    for(int i=1;i<size-1;i++) {
        if(c[i].empty()) continue;
        for(int j=1;j<size-1;j++) {
            cur[j] = cur[j-1]+pre[j]-pre[j-1]+(c[i].find(j)!=c[i].end()?c[i][j]:0);
            if(a[i]<INT_MAX&&b[j]<INT_MAX) res=max(res, cur[j]-a[i+1]-b[j+1]); 
        }
        pre = cur;
    }
    cout<<res<<endl;
    return 0;
}