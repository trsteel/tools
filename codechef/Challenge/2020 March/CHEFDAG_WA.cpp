#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

void cal(vector<vector<int> >& grid, int n, int K) {
    vector<vector<bool> > out(n+1, vector<bool>(n+1, true));
    for(int i=0; i<=n; i++) out[i][i] = false;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
        for(int k=0;k<K;k++) out[grid[k][j]][grid[k][i]] = false;
    }
    vector<int> in(n+1, 0);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        if(out[j][i]) in[i]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
    vector<int> next(n+1, 0), pre(n+1, 0);
    unordered_set<int> p;
    while(!q.empty()) {
        int t = q.size();
        vector<int> ans;
        while(t--) {
            int i=q.front(); q.pop();
            if(pre[i]==0) {
                for(int j: p) if(out[j][i] && next[j]==0) {
                    next[j] = i; pre[i] = j; p.erase(j); break;
                }
            }
            for(int j=1;j<=n;j++) {
                if(out[i][j] && --in[j]==0) q.push(j);
            }
            ans.push_back(i);
        }
        for(int i: ans) p.insert(i);
    }
    int size = 0;
    for(int i=1;i<=n;i++) if(pre[i]==0) size++;
    cout<<size<<endl;
    for(int i=1;i<=n;i++) cout<<next[i]<<" ";
    cout<<endl;
}

int main(){
    int t, n, k; cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<vector<int> > grid(k, vector<int>(n));
        for(int i=0;i<k;i++) for(int j=0;j<n;j++) {
            cin>>grid[i][j];
        }
        cal(grid, n, k);
    }
    return 0;
}