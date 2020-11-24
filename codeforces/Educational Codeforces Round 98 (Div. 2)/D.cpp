#include <iostream>
using namespace std;

int main() {
    long n; cin>>n;
    long long mod = 998244353;
    long long inv2 = (mod+1)/2;
    if(n==0) {
        cout<<1<<endl;
    } else if(n==1) {
        cout<<inv2<<endl;
    } else {
        long long a = inv2, b = inv2*inv2%mod, c;
        for(int i=2;i<n;i++) {
            c = (a*inv2%mod*inv2%mod + b*inv2%mod)%mod;
            a = b; b = c;
        }
        cout<<b<<endl;
    }
    return 0;
}