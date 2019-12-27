#include <iostream>
#include <vector>
using namespace std;

int cal(vector<int>& vec) {
    int n = vec.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    int res = 1;
    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(vec[i]%vec[j]==0) dp[i] = max(dp[i], dp[j]+1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    cout<<cal(vec)<<endl;
    return 0;
}