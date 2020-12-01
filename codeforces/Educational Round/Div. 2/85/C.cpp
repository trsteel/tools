#include <iostream>
#include <stdio.h>
using namespace std;

const long maxn = 300001;
long long a[maxn], b[maxn];

int main(){
    long long t, n; cin>>t;
    while(t--) {
        cin>>n;
        long long res = 0, ans = 0;
        for(long long i=0;i<n;i++) {
            scanf("%lld%lld", &a[i], &b[i]);
            res += a[i];
        }
        for(long long i=0;i<n;i++) {
            ans+=a[i]-min(b[(i+n-2)%n+1],a[i]);
			res=min(res,min(b[(i+n-2)%n+1],a[i]));
        }
        printf("%lld\n", res+ans);
    }
    return 0;
}