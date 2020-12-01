#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> res(n, 10);
    long long ans = 1, mod = 998244353;
    for(int i=1;i<n;i++) {
        res[i] = 9*(9*i+11)*ans%mod;
        ans = (ans*10)%mod;
    }
    for(int i=n-1;i>=0;i--) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}