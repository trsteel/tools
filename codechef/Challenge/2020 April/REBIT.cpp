#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long mod = 998244353;

void exgcd(long long a,long long b,long long& d,long long& x,long long& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

long long inv(long long a, long long p)
{
    long long d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}

vector<long long> merge(vector<long long> v1, vector<long long> v2, char c) {
    vector<long long> res(4, 0);
    if(c=='&') {
        res[1] = v1[1]*v2[1]%mod;
        res[2] = (v1[1]*v2[2]%mod+v1[2]*v2[1]%mod+v1[2]*v2[2]%mod)%mod;
        res[3] = (v1[1]*v2[3]%mod+v1[3]*v2[1]%mod+v1[3]*v2[3]%mod)%mod;
        res[0] = (1+mod*3-res[1]-res[2]-res[3])%mod;
    } else if(c=='|') {
        res[0] = v1[0]*v2[0]%mod;
        res[2] = (v1[0]*v2[2]%mod+v1[2]*v2[0]%mod+v1[2]*v2[2]%mod)%mod;
        res[3] = (v1[0]*v2[3]%mod+v1[3]*v2[0]%mod+v1[3]*v2[3]%mod)%mod;
        res[1] = (1+mod*3-res[0]-res[2]-res[3])%mod;
    } else {
        res[0] = (v1[0]*v2[0]%mod+v1[1]*v2[1]%mod+v1[2]*v2[2]%mod+v1[3]*v2[3]%mod)%mod;
        res[1] = (v1[0]*v2[1]%mod+v1[1]*v2[0]%mod+v1[2]*v2[3]%mod+v1[3]*v2[2]%mod)%mod;
        res[2] = (v1[0]*v2[2]%mod+v1[2]*v2[0]%mod+v1[1]*v2[3]%mod+v1[3]*v2[1]%mod)%mod;
        res[3] = (v1[0]*v2[3]%mod+v1[3]*v2[0]%mod+v1[1]*v2[2]%mod+v1[2]*v2[1]%mod)%mod;
    }
    return res;
}

// 0, 1, a, A
vector<long long> dfs(string& s, long long l, long long r) {
    // cout<<s<<l<<" "<<r<<endl;
    if(l==r) return {748683265, 748683265, 748683265, 748683265};
    if(l+4==r) return merge(dfs(s, l+1, l+1), dfs(s, r-1, r-1), s[l+2]);
    if(s[l+1]!='(') return merge(dfs(s, l+1, l+1), dfs(s, l+3, r-1), s[l+2]);
    long long d=0;
    for(long long i=l+1;i<r;i++) {
        if(s[i]==')' && --d==0)
            return merge(dfs(s, l+1, i), dfs(s, i+2, r-1), s[i+1]);
        else if(s[i]=='(') d++;
    }
    return {};
}

int main() {
	// your code goes here
    long long t; cin>>t;
    string s;
    while(t--) {
        cin>>s;
        auto res = dfs(s, 0, s.size()-1);
        for(auto i: res) cout<<i<<" ";
        cout<<endl;
    }
	return 0;
}