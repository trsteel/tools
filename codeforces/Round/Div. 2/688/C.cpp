#include <iostream>
#include <map>
#include <vector>
using namespace std;
long t, n;
string grid[2001];
vector<long> l[10], r[10];
long long ans[10];

void process() {
    for(int i=0;i<10;++i) l[i].clear(),r[i].clear(),ans[i]=0;
    for(long i=0;i<n;i++) for(long j=0;j<n;j++) {
        l[grid[i][j]-'0'].push_back(i);
    }
    for(long j=0;j<n;j++) for(long i=0;i<n;i++) {
        r[grid[i][j]-'0'].push_back(j);
    }
    for(long i=0;i<n;i++) for(long j=0;j<n;j++) {
        int u=grid[i][j]-'0';
        ans[u]=max(ans[u],1ll*max(j-1,n-j)*max(i-l[u].front(),l[u].back()-i));
        ans[u]=max(ans[u],1ll*max(i-1,n-i)*max(j-r[u].front(),r[u].back()-j));
    }
    for(int i=0;i<10;++i) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>grid[i];
        process();
    }
    return 0;
}