#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int dfs(vector<int>& vec, vector<vector<int> >& grid, 
        vector<vector<int> >& cache, int i, int op, int pre) {
    if(cache[i][op] != -1) return cache[i][op];
    if (op == 1) {
        int ans = 0;
        for(int j: grid[i]) if(j!=pre) ans += dfs(vec, grid, cache, j, 0, i);
        return cache[i][op] = ans;
    }
    int a = 0, b = vec[i];
    for(int j : grid[i]) if(j!=pre) {
        a += dfs(vec, grid, cache, j, 0, i);
        b += dfs(vec, grid, cache, j, 1, i);
    }
    return cache[i][op] = max(a, b);
}

int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    vector<vector<int> > grid(n);
    int a, b;
    for(int i=0;i<n-1;i++) {
        cin>>a>>b;
        grid[a-1].push_back(b-1);
        grid[b-1].push_back(a-1);
    }
    vector<vector<int> > cache(n, vector<int>(2, -1));
    cout<<dfs(vec, grid, cache, 0, 0, 0)<<endl;
    return 0;
}