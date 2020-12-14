#include <iostream>
#include <string.h>
using namespace std;

long long t, n, a[200005], cache[200005];

long dfs(long u, int t) {
    if(u==n) return 0;
    if(t==1) {
        if(u==n-1 || a[u+1]==0) {
            return dfs(u+1, t^1);
        } else {
            return dfs(u+2, t^1);
        }
    } else {
        if(cache[u]!=-1) return cache[u];
        long long ans = a[u] + dfs(u+1, t^1);
        if(u < n-1) ans = min(ans, a[u]+a[u+1]+dfs(u+2, t^1));
        return cache[u] = ans;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        memset(cache, -1, sizeof(cache));
        cout<<dfs(0, 0)<<endl;
    }
    return 0;
}