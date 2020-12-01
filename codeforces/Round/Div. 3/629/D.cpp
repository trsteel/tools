#include <iostream>
#include <queue>
using namespace std;
const long maxn = 200001;
long nums[maxn], n;

void dfs(long i, vector<long>& vec, long ans, long& res, vector<long>& path) {
    if(ans>=res) return;
    if(i==n-1) {
        if((vec[n-1]!=vec[0]||nums[0]==nums[n-1]) && ans < res) {
            res = ans, path.assign(vec.begin(), vec.end());
        }
        return;
    }
    if(nums[i]==nums[i+1]) {
        vec[i+1] = vec[i];
        dfs(i+1, vec, ans, res, path);
    }
    for(long c=1;c<=ans;c++) {
        if(nums[i]!=nums[i+1]&&c==vec[i]) continue;
        vec[i+1] = c;
        dfs(i+1, vec, ans, res, path);
    }
    vec[i+1] = ans+1;
    dfs(i+1, vec, ans+1, res, path);
}


void solve() {
    cin>>n;
    for(long i=0;i<n;i++) cin>>nums[i];
    long res = maxn;
    vector<long> vec(n, 1), path;
    dfs(0, vec, 1, res, path);
    cout<<res<<endl;
    for(long i: path) cout<<i<<" ";
    cout<<endl;
}

int main(){
    long long t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}