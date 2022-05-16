#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const long maxn = 1e5 + 1;

long t, n, k, m, x;

bool dfs(vector<vector<int> >& vec, vector<vector<pair<int, int> > >& idx, vector<int>& ans) {
    for(int i=0;i<k;i++) if(ans[i] < vec[i].size()) {
        int j = ans[i];
        int num = vec[i][j];
        for(auto& p: idx[num]) {
            if(p.first != i && p.second != j && ans[p.first]==p.second) {
                ans[i]++, ans[p.first]++;
                if(!dfs(vec, idx, ans)) return true;
                ans[i]--, ans[p.first]--;
            }
        }
    }
    return false;
}

bool check(vector<vector<int> >& vec) {
    vector<vector<pair<int, int> > > idx(n+1);
    for(int i=0;i<k;i++) {
        for(int j=0;j<vec[i].size();j++) {
            idx[vec[i][j]].push_back({i, j});
        }
    }
    vector<int> ans(k, 0);
    return dfs(vec, idx, ans);
}

int main() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<vector<int> > vec(k);
        for(int i=0;i<k;i++) {
            cin>>m;
            for(int j=0;j<n;j++) {
                cin>>x; vec[i].push_back(x);
            }
        }
        cout<<(check(vec)?"Kelly":"Nacho")<<endl;
    }
    return 0;
}