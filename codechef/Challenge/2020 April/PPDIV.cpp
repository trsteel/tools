#include <math.h>
#include <iostream>
#include <vector>

using namespace std;
long long mod = 1e9 + 7;

long long cal(long long n) {
    long long res = n%mod, r = sqrt(n);
    vector<bool> vis(r+1, false);
    for(long long i=2;i<=r;i++) if(!vis[i]) {
        long long ans = i*i;
        while(ans<=n) {
            if(ans<=r) vis[ans] = true;
            res = (res+ans*(n/ans))%mod;
            if(n/ans<i) break;
            ans *= i;
        }
    }
    return res;
}

int main(){
    long long t, n; cin>>t;
    while(t--) {
        cin>>n;
        cout<<cal(n)<<endl;
    }
    return 0;
}