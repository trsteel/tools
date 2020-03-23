#include <iostream>
#include <vector>
using namespace std;

long sum(string& s, int l, int r) {
    long ans = 0;
    for(int i=l;i<=r;i++) ans+=s[i]-'0';
    return ans;
}

void dfs(string& s, int l, int r, int a, int b, bool paint, long& res) {
    if(l>a || r<b) return;
    if(l==a && r==b) {
        res = max(res, sum(s, l, r)); return;
    }
    if(paint) {
        dfs(s, l, r, a-1, b, !paint, res);
        dfs(s, l, r, a, b+1, !paint, res);
    } else {
        dfs(s, l+1, r, a, b, !paint, res);
        dfs(s, l, r-1, a, b, !paint, res);
    }
}

int main(){
    long T, n; cin>>T;
    string s;
    for(long t=1;t<=T;t++) {
        cin>>n>>s;
        long res = 0;
        for(int i=0;i<n;i++)
            dfs(s, 0, n-1, i, i, false, res);
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}