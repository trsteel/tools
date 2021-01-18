#include <iostream>

using namespace std;
const long maxn = 200001;
long t, n, m, dpl[maxn][2], dpr[maxn][2], sum[maxn];
string s;

long cal(long l, long r) {
    long le = 0, ri = 0;
    if(l>0) {
        le = min(le, dpl[l-1][0]);
        ri = max(ri, dpl[l-1][1]);
        // cout<<l<<" "<<r<<"left"<<le<<" "<<ri<<endl;
    }
    if(r < n-1) {
        long d = sum[r+1]-sum[l];
        le = min(le, dpr[r+1][0]-d);
        ri = max(ri, dpr[r+1][1]-d);
        // cout<<l<<" "<<r<<"right"<<le<<" "<<ri<<endl;
    }
    // cout<<l<<" "<<r<<" "<<le<<" "<<ri<<endl;
    return ri-le+1;
}

void solve() {
    long ans = 0, l=0, r=0;
    sum[0] = 0;
    for(int i=0;i<n;i++) {
        if(s[i]=='-') ans--;
        else ans++;
        sum[i+1] = ans;
        if(ans < l) l = ans;
        if(ans > r) r = ans;
        dpl[i][0]=l, dpl[i][1]=r;
    }
    l = ans, r = ans;
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='+') ans--;
        else ans++;
        if(ans < l) l = ans;
        if(ans > r) r = ans;
        dpr[i][0]=l, dpr[i][1]=r;
    }
    for(int i=0;i<m;i++) {
        cin>>l>>r;
        cout<<cal(l-1, r-1)<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>m>>s;
        solve();
    }
    return 0;
}