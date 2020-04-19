
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

long long mod = 1e9 + 7;

void gcd(long long n, vector<long long>& res) {
    // long long r = sqrt(n);
    for(long long i=2;i<=n;i++) if(n%i==0) {
        res.push_back(i);
    }
}

long long pow(long long base, long long n) {
    long long res = 1;
    for(long long i=0;i<n;i++) res = res*base%mod;
    return res;
}

int main(){
    long long t, x, k; cin>>t;
    while(t--) {
        cin>>x>>k;
        vector<long long> a, b;
        gcd(x, a); gcd(k, b);
        long long p = 0, q = 0;
        for(long long i: a) {
            p = (p+pow(i, k))%mod;
        }
        for(long long i: b) {
            q = (q+i*x)%mod;
        }
        cout<<p<<" "<<q<<endl;
    }
    return 0;
}