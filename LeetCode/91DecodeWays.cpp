/*
 * dp算法
 */

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0)return 0;
        int dp[n+1];
        dp[n]=1;
        dp[n-1]=(s[n-1]=='0')?0:1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0')dp[i]=0;
            else if((s[i]-'0')*10+(s[i+1]-'0')<27) dp[i]=dp[i+1]+dp[i+2];
            else dp[i]=dp[i+1];
        }
        return dp[0];
    }
};
