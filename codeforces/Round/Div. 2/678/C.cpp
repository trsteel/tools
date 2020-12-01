#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;
long long A(long long n, long long m) {
//    if(n<=0 || m > n) return 0;
    long long res = 1;
    for(long long i=0;i<m;i++) {
        res = res*(n-i)%mod;
    }
    return res;
}

int main() {
    long long n, x, pos;
    cin>>n>>x>>pos;
    long long left = 0, right = 0;
    long long l = 0, r = n;
    while(l < r) {
        long long mid = (l+r)>>1;
        if(mid == pos) l=mid+1;
        else if(mid > pos) right++, r = mid;
        else left++, l = mid+1;
    }
//    cout<<left<<" "<<right<<endl;
    long long res = 1;
    res = res*A(x-1, left)%mod;
    res = res*A(n-x, right)%mod;
    res = res*A(n-left-right-1, n-left-right-1)%mod;
    cout<<res<<endl;
    return 0;
}
