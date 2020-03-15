#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include<queue>
#include <math.h>
#include <algorithm>
#include <set>
using namespace std;

int cal(vector<unordered_set<int> >& grid, vector<int>& vec, multiset<int>& ws) {
    int n = grid.size();
    // 拓扑排序
    queue<int> q;
    for(int i=0;i<n;i++) if(grid[i].size()==1) q.push(i);
    vector<int> limit(n, -1);
    int res = 0, idx=0, u, w, lm, cur;
    while(!q.empty()) {
        u = q.front(); q.pop();
        // cout<<res<<" "<<u<<endl;
        w = vec[idx++];
        lm = max(w, limit[u]);
        auto it = ws.upper_bound(lm);
        if(it == ws.end()) it = ws.begin();
        cur = *it; 
        ws.erase(it);
        if(cur <= lm) { res++; }
        for(int v: grid[u]) {
            limit[v] = max(limit[v], w);
            grid[v].erase(u);
            if(grid[v].size()==1) q.push(v);
        }
        grid[u].clear();
    }
    // cout<<"res"<<res<<endl;
    return res;
}

int main(){
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<unordered_set<int> > grid(n);
        int u, v, w;
        multiset<int> ms;
        for(int i=0;i<n-1;i++) {
            cin>>u>>v>>w;
            ms.insert(w);
            grid[u-1].insert(v-1);
            grid[v-1].insert(u-1);
        }
        vector<int> vec(ms.begin(), ms.end());
        multiset<int> ws;
        for(int i=0;i<n;i++) {
            cin>>w; ws.insert(w);
        }
        cout<<cal(grid, vec, ws)<<endl;
    }
    return 0;
}