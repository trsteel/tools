/**
 * 关键点: 注意理清令牌和机器的表示顺序
 **/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cal(vector<vector<vector<int> > >& grid, int s, long n) {
    map<vector<int>, long> cache;
    long idx = 1;
    vector<int> ans = {1, s};
    while(idx < n) {
        if(cache.find(ans) != cache.end()) {
            long d = idx - cache[ans];
            idx += ((n-idx)/d) * d;
            if(idx >= n) break;
        }
        cache[ans] = idx++;
        ans = grid[ans[1]-1][ans[0]-1];
    }
    return ans[1];
}

int main(){
    long m, t, s, n;
    cin>>m>>t>>s>>n;
    vector<vector<vector<int> > > grid(m, 
        vector<vector<int> >(t, vector<int>(2)));
    for(int i=0;i<m;i++) {
        for(int j=0;j<t;j++) {
            cin>>grid[i][j][0]>>grid[i][j][1];
        }
    }
    cout<<cal(grid, s, n)<<endl;
    return 0;
}