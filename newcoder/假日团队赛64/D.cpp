#include <iostream>
#include <vector>
#include <stack>
using namespace std;
string s, t;
vector<long> nt;
vector<bool> vis;

long find_next(long x) {
    long y = nt[x];
    while(y < s.size() && vis[y]) y = nt[y];
    return nt[x] = y;
}

bool dfs(long long x) {
    stack<long> st;
    long j = x;
    for(long i=0;i<t.size() && j<s.size();i++,j=find_next(j)) {
        if(s[j]==t[i]) {
            st.push(j); continue;
        }
        for(; i>0; i--) {
            long tp = st.top(); st.pop();
            if(s[tp]==t[i] && dfs(j)) break;
            j = tp;
        }
        if(i==0) return false;
    }
    cout<<x<<" "<<j<<endl;
    nt[x] = j, vis[x] = true;
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>t;
    long long n = s.size();
    nt = vector<long>(n);
    vis = vector<bool>(n, false);
    for(long long i=0;i<n;i++) nt[i] = i+1;
    long ans = 0;
    while(ans < s.size()) {
        if(!vis[ans]) dfs(ans);
        ans = find_next(ans);
    }
    long long idx = 0;
    while(idx < s.size()) {
        if(!vis[idx]) cout<<s[idx];
        idx = find_next(idx);
    }
    cout<<endl;
    return 0;
}