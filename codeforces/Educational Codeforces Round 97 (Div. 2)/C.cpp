#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(){
    long q, n;
    cin>>q;
    while(q--) {
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(vec.begin(), vec.end());
        vector<int> dp(n+1, INT_MAX/2);
        dp[0] = 0;
        for(int i=1;i<=2*n;i++) {
            for(int j=n;j>0;j--) {
                dp[j] = min(dp[j], dp[j-1]+abs(vec[j-1]-i));
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}