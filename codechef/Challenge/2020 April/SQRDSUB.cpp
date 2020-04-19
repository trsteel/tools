/**
 * 关键点: 只有4k+2形式的整数不能写成两数平方差
 **/
#include <iostream>
#include <string.h>
using namespace std;
const long maxn = 100010;
long long nums[maxn], dp[maxn][3];

long long cal(long long x) {
    if(x<0) x = -x;
    if(x%2) return 0;
    if(x%4) return 1;
    return 2;
}

int main() {
	// your code goes here
	long long t, n; cin>>t;
	while(t--) {
	    cin>>n;
	    for(long long i=0;i<n;i++) cin>>nums[i];
	    long long res = 0;
	    memset(dp, 0, sizeof(dp));
	    for(long long i=0;i<n;i++) {
	        long long ans = cal(nums[i]);
	        if(ans==0) dp[i+1][0]=dp[i][0]+1, dp[i+1][1]=dp[i][1], dp[i+1][2]=dp[i][2];
	        else if(ans==1) dp[i+1][1] = dp[i][0]+1, dp[i+1][2] = dp[i][1]+dp[i][2];
	        else dp[i+1][2] = dp[i][0]+dp[i][1]+dp[i][2]+1;
	        res += dp[i+1][0] + dp[i+1][2];
	    }
	    cout<<res<<endl;
	}
	return 0;
}