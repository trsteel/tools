#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main(){
    long n; cin>>n;
    vector<long> vec(n);
    for(long& i: vec) cin>>i;
    queue<vector<long> > q;
    q.push({0, 0});
    long res = INT_MAX;
    vector<long> vis(n, INT_MAX);
    while(!q.empty()) {
        auto v = q.front(); q.pop();
        if(v[0]==n-1) {
            res = min(res, v[1]); continue;
        }
        if(v[1]>=vis[v[0]]) continue;
        vis[v[0]] = v[1];
        if(vec[v[0]]>0) {
            for(long j=1;j<=vec[v[0]];j++) {
                if(v[0]+j>=n) break;
                q.push({v[0]+j, v[1]+1});
            }
        } else if(vec[v[0]]<0) {
            for(long j=vec[v[0]];j<0;j++) {
                if(v[0]+j>=0) q.push({v[0]+j, v[1]+1});
            }
        }
    }
    cout<<(res==INT_MAX?-1:res)<<endl;
    return 0;
}