#include <iostream>
#include <vector>
using namespace std;

void dfs(long &res, long x, long ans, vector<bool>& vis) {
    if(x == 0) {
        if(res == -1 || ans < res) res = ans;
        return;
    }
    if(x < 0) return;
    for(long i=1;i<10 && i <= x;i++) if(!vis[i]) {
        vis[i] = true;
        dfs(res, x-i, ans*10+i, vis);
        vis[i] = false;
    }
}

int main(){
    long t, x;
    cin>>t;
    while(t--) {
        cin>>x;
        vector<bool> vis(10, false);
        long res = -1;
        dfs(res, x, 0, vis);
        cout<<res<<endl;
    }
    return 0;
}