#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 100002;
const long mod = 1e9 + 7;
long a[maxn], b[maxn];

void pre_process(int n) {
    if(a[0]==1) return;
    long ans = 0;
    for(int i=0;i<n;i++) {
        b[i] = ans + a[i];
        bool add = false;
        if(i<n-1 && a[i+1]==1) {
            b[i+1] = ans + a[i] + (a[i]%2==1?0:1);
            ans += a[i] + (a[i]%2==1?0:-1);
            add = true;
        } else if(i==n-1) {
            ans += a[i] + (a[i]%2==1?0:-1);
        } else {
            ans += a[i] + (a[i]%2==0?0:-1);
        }
        if(add) i++;
        ans %= mod;
    }
    b[n] = a[n-1]==1?b[n-1]:ans;
}

int main() {
    // your code goes here
    long long t, n, q, r;
    scanf("%lld", &t);
    while(t--) {
        scanf("%ld", &n);
        for(int i=0;i<n;i++) scanf("%ld", &(a[i]));
        pre_process(n);
        // for(int i=0;i<=n;i++) cout<<b[i]<<" ";
        // cout<<endl;
        scanf("%lld", &q);
        while(q--) {
            scanf("%lld", &r);
            r--;
            long long x = (r / n)%mod;
            if(a[0]==1) {
                if(n==1) printf("%ld\n", (x+1)%mod);
                else if(r%n==0) printf("%ld\n", max(x, 1LL));
                else printf("%ld\n", (x+1)%mod);
                continue;
            }
            printf("%ld\n", (b[n]*x%mod + b[r % n])%mod);
        }
    }
    return 0;
}