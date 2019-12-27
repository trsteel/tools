#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal(vector<int>& vec, int k) {
    int n = vec.size();
    vector<int> sum(n+1, 0);
    for(int i=0;i<n;i++) sum[i+1]=sum[i]+vec[i];
    vector<int> max_sum(n, 0);
    max_sum[n-1] = sum[n];
    for(int i=n-2;i>=0;i--) max_sum[i] = max(max_sum[i+1], sum[i+1]);
    int res = sum[k];
    for(int i=0;i<=n-k;i++) {
        int ans = max_sum[i+k-1] - sum[i];
        // cout<<i<<k<<ans<<endl;
        res = max(res, ans);
    }
    return res;
}

int main(){
    int n, k; cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cout<<cal(vec, k)<<endl;
    return 0;
}