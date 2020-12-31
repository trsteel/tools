#include <iostream>

using namespace std;

int main(){
    long long n, mod = 1e9 + 7;
    cin>>n;
    if(n==3) {
        cout<<2<<endl; return 0;
    }
    long long a = 1, b = 1;
    for(long long i=1;i<=n;i++) {
        a = a*i%mod;
        if(i>1) b = b*2%mod;
        // cout<<i<<endl;
    }
    a = (a-b+mod) % mod;
    cout<<a<<endl;
    return 0;
}