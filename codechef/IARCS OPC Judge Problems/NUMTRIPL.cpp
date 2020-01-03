/**
 * 关键点: 输入的数据中可能存在端点相同价值不同的两条路径
 **/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <queue>
using namespace std;

long cal(vector<unordered_map<long, long> >& grid, long a, long b) {
    map<long, vector<long> > m;
    vector<bool> vis(grid.size(), false);
    m[0].push_back(a);
    while(!m.empty()) {
        long d = m.begin()->first;
        for(long i: m[d]) {
            if(i==b) return d;
            if(vis[i]) continue;
            vis[i] = true;
            for(auto& it2 : grid[i]) {
                m[d+it2.second].push_back(it2.first);
            }
        }
        m.erase(d);
    }
    return -1;
}

int main(){
    long m, a, b;
    cin>>m>>a>>b;
    vector<unordered_map<long, long> > grid(2001);
    long x, y, z;
    for(long i=0;i<m;i++) {
        cin>>x>>y>>z;
        if(grid[x][z]>0) y = min(y, grid[x][z]);
        grid[x][z] = y;
        grid[z][x] = y;
    }
    long res = cal(grid, a, b);
    cout<<(res==-1?"NO":"YES")<<endl;
    if (res != -1) cout<<res<<endl;
    return 0;
}