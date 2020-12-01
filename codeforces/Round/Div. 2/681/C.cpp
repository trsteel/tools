#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<pair<long long, long long>> vec(n);
        for(long long i=0;i<n;i++) {
            cin>>vec[i].first;
        }
        for(long long i=0;i<n;i++) {
            cin>>vec[i].second;
        }
        sort(vec.rbegin(), vec.rend());
        long long ans = 0, res = vec[0].first;
        for(long long i=1;i<n;i++) {
            ans += vec[i-1].second;
            res = min(res, max(ans, vec[i].first));
        }
        res = min(res, ans+vec[n-1].second);
        cout<<res<<endl;
     }
    return 0;
}