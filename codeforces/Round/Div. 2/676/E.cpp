#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
    long long n, a[200001];
    cin>>n;
    for(long long i=0;i<n;i++) cin>>a[i];
    long long x = 0, y = 0, sum = 0, ans = INT_MIN;
    for(long long i=0;i<n;i++) {
        sum += a[i];
        if(i&1) x+=a[i];
        else y += a[i];
    }
    sort(a, a+n);
    if(n%3==1) ans=sum;
    for(long long i=0;i<n;i++) {
        sum -= 2*a[i];
        if((n+i)%3==0) {
            if(sum == x-y || sum == y-x) {
                ans = max(ans, sum + 2*(a[i]-a[i+1]));
            } else ans = max(ans, sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}
