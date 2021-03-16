#include <iostream>
#include <string.h>
using namespace std;
const long maxn = 500001;
long t, n, h[maxn], dp[maxn];

bool match(int i, int j, int k) {
    long a = (h[i]-h[k])*(j-k);
    long b = (h[j]-h[k])*(i-k);
    return a >= b;
}

long cal() {
    memset(dp, -1, sizeof(dp));
    long res = 0;
    for(int i=1;i<n;i++) {
        int j = i-1;
        while(j>0 && dp[j]>=0 && match(i, j, dp[j])) j = dp[j];
        dp[i] = j;
        res = max(res, i-dp[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>h[i];
        cout<<cal()<<endl;
    }
    return 0;
}
