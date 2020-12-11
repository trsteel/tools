#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long n, k; cin>>n>>k;
    vector<long> p(n), idx(n);
    for(long i=0;i<n;i++) {
        cin>>p[i]; idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&p](int i, int j) {
        return p[i] > p[j];
    });
    vector<long> ans(idx.begin(), idx.begin()+k);
    sort(ans.begin(), ans.end());
    long long sum = p[ans[0]], res = 1, mod = 998244353;
    for(long i=1;i<k;i++) {
        sum += p[ans[i]];
        res = (res*(ans[i]-ans[i-1]+1))%mod;
    }
    cout<<sum<<" "<<res<<endl;
    return 0;
}