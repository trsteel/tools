#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin>>s;
    long long mod = 1e9 + 7, num=0;
    vector<pair<long long, long long>> dp(3, pair<long long, long long>(0, 0));
    for(long i=0;i<s.size();i++) {
        num = (num*10 + s[i]-'0') % mod;
        dp[2].first = (dp[2].first + dp[1].first)%mod;
        dp[2].second = (dp[2].second + dp[1].second)%mod;
        dp[2].first = (dp[2].first * 10 + dp[2].second * (s[i]-'0')) % mod;
        if(i > 0) {
            dp[2].first = (dp[2].first + s[i]-'0')%mod;
            dp[2].second = (dp[2].second + 1)%mod;
        }
        dp[1].first = (dp[1].first + dp[0].first)%mod;
        dp[1].second = (dp[1].second + dp[0].second)%mod;
        dp[0].first = num;
        dp[0].second = 1;
    }
    cout<<(dp[2].first + dp[1].first)%mod<<endl;
    return 0;
}
