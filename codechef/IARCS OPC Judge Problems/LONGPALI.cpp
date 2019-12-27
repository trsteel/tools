#include <iostream>
#include <vector>

using namespace std;

string cal(string& s) {
    int n = s.size();
    vector<vector<bool> > dp(n, vector<bool>(n, false));
    string res = "";
    for(int i=0;i<n;i++) {
        dp[i][i] = true;
        res = s.substr(i, 1);
    }
    for(int i=0;i<n-1;i++) {
        if(s[i]==s[i+1]) { dp[i][i+1] = true; res = s.substr(i, 2); }
    }
    for(int len=3;len<=n;len++) {
        for(int i=0;i<=n-len;i++) {
            if(dp[i+1][i+len-2] && s[i]==s[i+len-1]) {
                dp[i][i+len-1] = true; res = s.substr(i, len);
                // cout<<i<<len<<res<<endl;
            }
        }
    }
    return res;
}

int main(){
    int n; cin>>n;
    string s; cin>>s;
    string res = cal(s);
    cout<<res.size()<<endl<<res<<endl;
    return 0;
}