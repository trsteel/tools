#include <iostream>
#include <string.h>
using namespace std;

const long maxn = 5e6 + 1;
long long n, a, tree[maxn<<1][2], cnt = 1, size[maxn<<1], dp[35][2];

void insert(int x) {
    long root = 0;
    for(int i=30;i>=0;i--) {
        int net = (x>>i)&1;
        dp[i][net] += size[tree[root][net^1]];
        if(!tree[root][net]) tree[root][net]= cnt++;
        root = tree[root][net];
        size[root]++;
    }
}

int main() {
    cin>>n;
    memset(dp, 0, sizeof(dp));
    memset(size, 0, sizeof(size));
    for(int i=1;i<=n;i++) {
        cin>>a; insert(a);
    }
    long long ans = 0, sum = 0;
    for(int i=30; i>=0; i--) {
        if(dp[i][0]>dp[i][1]) {
            ans |= (1<<i), sum += dp[i][1];
        } else sum += dp[i][0];
    }
    cout<<sum<<" "<<ans<<endl;
    return 0;
}
