/**
 * 关键点: 删除关键节点后图的连通性会改变 (连通子图个数增加)
 * */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int find(vector<int>& parent, int x) {
    if(parent[x] == -1 || parent[x]==x) return parent[x] = x;
    return parent[x] = find(parent, parent[x]);
}

int part(vector<unordered_set<int> >& grid, int x) {
    int n = grid.size();
    vector<int> parent(n, -1);
    for(int i=0;i<n;i++) {
        if(i==x || grid[i].empty()) continue;
        int p = find(parent, i);
        for(int j: grid[i]) {
            if(j==x) continue;
            int q = find(parent, j);
            if(p!=q) parent[q] = p;
        }
    }
    unordered_set<int> st;
    for(int i=0;i<n;i++) {
        if(i!=x) st.insert(find(parent, i));
    }
    return st.size();
}

vector<int> cal(vector<unordered_set<int> >& grid) {
    int n = grid.size();
    int p = part(grid, -1);
    vector<int> res;
    for(int i=0;i<n;i++) {
        if(part(grid, i) > p) res.push_back(i);
    }
    return res;
}

int main(){
    int n, m; cin>>n>>m;
    vector<unordered_set<int> > grid(n);
    int i, j;
    while(m--) {
        cin>>i>>j;
        grid[i-1].insert(j-1);
        grid[j-1].insert(i-1);
    }
    auto res = cal(grid);
    cout<<res.size()<<endl;
    for(int i: res) cout<<(i+1)<<endl;
    return 0;
}