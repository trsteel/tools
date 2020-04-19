#include <iostream>

using namespace std;

int main(){
    long long t, n; cin>>t;
    while(t--) {
        cin>>n;
        long long cnt = 0, f, t=0;
        for(long long i=2;i<=n;i++) {
            if(n%i==0 && ++cnt==2) {f=i; break;}
        }
        string s = to_string(n), res = "";
        for(long long i=0;i<s.size();i++) {
            if(s[i]>s[t]) t = i;
            if((s[i]-'0')%2==0) res.push_back(s[i]+1);
            else res.push_back(s[i]);
        }
        t = s.size()-t;
        cout<<f<<" "<<t<<" "<<res<<endl;
    }
    return 0;
}