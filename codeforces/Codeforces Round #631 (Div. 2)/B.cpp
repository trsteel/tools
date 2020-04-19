#include <iostream>
#include <vector>
#include <set>
using namespace std;
const long maxn = 200001;
long nums[maxn];

int main(){
    long t, n; cin>>t;
    while(t--) {
        cin>>n;
        for(long i=0;i<n;i++) cin>>nums[i];
        set<long> st;
        vector<long> res, cnt(n+1, 0), cnt1(n+1, 0);
        long ma = 0, max_cnt = 0;
        for(long i=0;i<n;i++) {
            ma = max(ma, nums[i]);
            max_cnt = max(max_cnt, ++cnt[nums[i]]);
            if(max_cnt>1) break;
            if(ma==i+1) st.insert(ma);
        }
        ma = 0, max_cnt = 0;
        for(long i=n-1;i>=0;i--) {
            ma = max(ma, nums[i]);
            max_cnt = max(max_cnt, ++cnt1[nums[i]]);
            if(max_cnt>1) break;
            if(ma==n-i&&st.count(n-ma))
                res.push_back(n-ma);
        }
        cout<<res.size()<<endl;
        for(long i: res) cout<<i<<" "<<(n-i)<<endl;
    }
    return 0;
}