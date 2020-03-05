#include <iostream>
#include <algorithm>
using namespace std;

void cal(string& s) {
    int k = 1;
    string res = s;
    for(int i=2; i<=s.size(); i++) {
        string ans = s.substr(0, i-1);
        if((s.size()-i)%2==0) reverse(ans.begin(), ans.end());
        ans = s.substr(i-1) + ans;
        // cout<<i<<ans<<endl;
        if(ans < res) res = ans, k = i;
    }
    cout<<res<<endl<<k<<endl;
}

int main(){
    long long t, n; cin>>t;
    string s;
    while(t--) {
        cin>>n>>s;
        cal(s);
    }
    return 0;
}