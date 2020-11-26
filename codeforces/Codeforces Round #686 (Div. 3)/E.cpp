#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long t, n, u, v;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<vector<long long> > adj(n+1);
        vector<long long> in(n+1, 0);
        for(long long i=0;i<n;i++) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            in[u]++, in[v]++;
        }
        vector<bool> circle(n+1, true);
        queue<long long> q;
        for(long long i=1;i<=n;i++) if(in[i]==1) {
            q.push(i);
        }
        while(!q.empty()) {
            long long x = q.front(); q.pop();
            circle[x] = false;
            for(long long y: adj[x]) {
                in[y]--;
                if(in[y]==1 && circle[y]) q.push(y);
            }
        }
        long long res = n * (n-1);
        vector<bool> vis(n+1, false);
        for(long long i=1;i<=n;i++) if(circle[i]) {
            queue<long long> qu;
            for(long long j: adj[i]) if(!circle[j]) {
                qu.push(j);
            }
            long long ans = 1;
            vis[i] = true;
            while(!qu.empty()) {
                long long x = qu.front(); qu.pop();
                ans++; vis[x] = true;
                for(long long y: adj[x]) if(!vis[y]) {
                    qu.push(y);
                }
            }
            res -= ans*(ans-1)/2;
            // cout<<i<<" "<<ans<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}