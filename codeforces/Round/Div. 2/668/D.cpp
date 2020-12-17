#include <iostream>
#include <vector>
using namespace std;

const long maxn = 100001;

long long t, n, a, b, da, db, u, v;
vector<long> adj[maxn];

bool cal() {
    return true;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>a>>b>>da>>db;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<(cal()?"Alice":"Bob")<<endl;
    }
    return 0;
}