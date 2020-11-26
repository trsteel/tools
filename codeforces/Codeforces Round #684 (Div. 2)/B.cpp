#include <iostream>
using namespace std;

const long long maxn = 1001;
long long a[maxn*maxn];

int main(){
    long long t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(long long i=0;i<n*k;i++) cin>>a[i];
        long long mid = (n-1)/2, res = 0;
        for(long long i=mid*k; i<n*k; i+=n-mid) {
            res += a[i];
        }
        cout<<res<<endl;
    }
    return 0;
}