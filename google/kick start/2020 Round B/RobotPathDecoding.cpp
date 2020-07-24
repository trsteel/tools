#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long mod = 1e9;

long find(string& s, long l, long r) {
    if(s[l]!='(') return l+1;
    long d = 1;
    for(long i=l+1;i<=r;i++) {
        if(s[i]=='(') d++;
        else if(s[i]==')') if(--d==0) return i;
    }
    return r;
}

// S, E
pair<long long, long long> dfs(string& s, long l, long r) {
    // cout<<l<<" "<<r<<endl;
    if(s[l]=='(') return dfs(s, l+1, r-1);
    pair<long long, long long> p = make_pair(0, 0);
    for(long i=l;i<=r;i++) {
        if(s[i]=='S') p.first++;
        else if(s[i]=='N') p.first--;
        else if(s[i]=='E') p.second++;
        else if(s[i]=='W') p.second--;
        else {
            long long ans = 0;
            while(s[i]>='0'&&s[i]<='9') {
                ans = (ans*10 + s[i++] - '0')%mod;
            }
            long j = find(s, i, r);
            auto q = dfs(s, i, j);
            // cout<<ans<<" "<<i<<" "<<j<<" "<<q.first<<" "<<q.second<<endl;
            p.first += q.first*ans;
            p.second += q.second*ans;
            i = j;
        }
        p.first %= mod;
        p.second %= mod;
    }
    return p;
}

int main(){
    long t; cin>>t;
    for(long tt=1;tt<=t;tt++) {
        string s; cin>>s;
        auto p = dfs(s, 0, s.size()-1);
        long long x = (p.first+mod+1)%mod;
        if(x==0) x+=mod;
        long long y = (p.second+mod+1)%mod;
        if(y==0) y+=mod;
        cout<<"Case #"<<tt<<": "<<y<<" "<<x<<endl;
    }
    return 0;
}