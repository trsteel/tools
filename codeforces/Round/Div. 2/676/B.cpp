#include <iostream>
#include <vector>
using namespace std;

int main() {
    long t, n;
    char a[201][201];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
        vector<pair<int, int>> res;
        if(a[1][2]==a[2][1]) {
            if(a[n-1][n]==a[1][2]) res.push_back({n-1, n});
            if(a[n][n-1]==a[1][2]) res.push_back({n, n-1});
        } else if(a[n-1][n]==a[n][n-1]) {
            if(a[1][2]==a[n-1][n]) res.push_back({1, 2});
            if(a[2][1]==a[n-1][n]) res.push_back({2, 1});
        } else {
            res.push_back({2, 1});
            if(a[n-1][n]==a[1][2]) res.push_back({n-1, n});
            if(a[n][n-1]==a[1][2]) res.push_back({n, n-1});
        }
        cout<<res.size()<<endl;
        for(auto& v: res) cout<<v.first<<" "<<v.second<<endl;
    }
    return 0;
}
