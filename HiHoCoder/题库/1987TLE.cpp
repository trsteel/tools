// TLE
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
bool match(string& s, int l, int r) {
    int len = r-l+1;
    if(len==1) return false;
    for(int k=1;k<len;k++) {
        if(len%k!=0) continue;
        bool valid = true;
        for(int i=0;i<k;i++) {
            for(int j=k;j<len;j+=k) {
                if(s[i+l]!=s[j+i+l]) {valid=false;break;}
            }
            if(!valid) break;
        }
        if(valid) return true;
    }
    return false;
}

bool same(string& s, int i, int j, int len) {
    for(int k=0;k<len;k++) if(s[i+k]!=s[j+k]) return false;
    return true;
}

long find(int n, string& s) {
    vector<vector<unordered_set<int> > > valid(n, vector<unordered_set<int> >(n));
    for(int i=n-1;i>=0;i--) {
        for(int j=n-1;j>i;j--) {
            int len = j-i+1;
            for(int k=1;k<len;k++) {
                if(len%k==0 && (valid[i+k][j].count(k)>0 || k*2==len) && same(s, i, i+k, k)) {
                    valid[i][j].insert(k);
                }
            }
        }
    }
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) cout<<!valid[i][j].empty()<<match(s, i, j)<<" ";
    //     cout<<endl;
    // }
    long mod = 1e9 + 7;
    vector<long> dp(n, 0);
    for(int i=1;i<n;i++) {
        if(!valid[0][i].empty()) dp[i] = 1;
        for(int j=1;j<i;j++) {
            if(!valid[j+1][i].empty()) dp[i] = (dp[i]+dp[j])%mod;
        }
        // cout<<dp[i]<<endl;
    }
    return dp[n-1];
}

int main() {
    int t; cin>>t;
    while(t--) {
        int n; string s;
        cin>>n>>s;
        cout<<find(n, s)<<endl;
    }
    return 0;
}