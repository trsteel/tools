#include <iostream>
#include <vector>
#include<numeric>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> ans(9, 0);
        while(n--) {
            int p, s; cin>>p>>s;
            if(p<=8) ans[p] = max(ans[p], s);
        }
        cout<<accumulate(ans.begin(), ans.end(), 0)<<endl;
    }
    return 0;
}