#include <iostream>
#include <vector>
using namespace std;

bool cal(vector<long long>& vec, long long k) {
    vector<bool> vis(1000, false);
    for(long long i: vec) {
        long long j = 0, ans;
        while(i>0) {
            ans = i%k;
            if(ans>1) return false;
            if(ans==1) {
                if(vis[j]) return false;
                vis[j] = true;
            }
            i /= k;
            j++;
        }
    }
    return true;
}

int main(){
    long long t, n, k; cin>>t;
    while(t--) {
        cin>>n>>k;
        vector<bool> vis(1000, false);
        int ma = 0;
        vector<long long> vec(n);
        for(long long& i: vec) cin>>i;
        cout<<(cal(vec, k)?"YES":"NO")<<endl;
    }
    return 0;
}