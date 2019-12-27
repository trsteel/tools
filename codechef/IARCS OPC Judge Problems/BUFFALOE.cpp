/**
 * 关键点: dfs时需要通过缓存剪枝，探索时注意顺序
 **/
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void dfs(vector<int>& vec, vector<vector<int> >& cache, 
        int k, int start, int ans, int stock, int& res) {
    if(start == vec.size() || k <= 0) {
        res = max(res, ans); return;
    }
    if(cache[start][2*k+stock] >= ans) return;
    cache[start][2*k+stock] = ans;
    if(stock==0) dfs(vec, cache, k-1, start+1, ans-vec[start], 1, res);
    else if(stock==1) dfs(vec, cache, k-1, start+1, ans+vec[start], 0, res);
    dfs(vec, cache, k, start+1, ans, stock, res);
}

int cal(vector<int>& vec, int k) {
    int res = 0, n = vec.size();
    vector<vector<int> > cache(n, vector<int>(2*k+2, INT_MIN));
    dfs(vec, cache, k, 0, 0, 0, res);
    return res;
}

int main(){
    int n, k; cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cout<<cal(vec, k);
    return 0;
}