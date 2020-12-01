#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    long t, n, m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        vector<vector<long>> grid(n, vector<long>(m, 0));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>grid[i][j];
        vector<long> vec(n);
        unordered_map<long, int> um;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
            cin>>vec[j];
            if(i==m-1) um[vec[j]] = j;
        }
        int idx = 0;
        for(int i=0;i<m;i++) if(um.count(grid[0][i])) {
            idx = i; break;
        }
        sort(grid.begin(), grid.end(), [&idx, &um](vector<long>& v1, vector<long>& v2){
            return um[v1[idx]] < um[v2[idx]];
        });
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) cout<<grid[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
