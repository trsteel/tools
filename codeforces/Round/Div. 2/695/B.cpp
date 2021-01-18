#include <iostream>
#include <vector>
using namespace std;
const long long maxn = 300005;
long long t, n, a[maxn];

bool valid(long long l, long long r, long long i) {
    return (i>l && i>r) || (i<l && i<r);
}

bool match(long long i) {
    if(i==0 || i>=n-1) return false;
    return valid(a[i-1], a[i+1], a[i]);
}

long long solve() {
    vector<long long> l(n, 0), r(n, 0);
    long long ans = 0;
    for(long long i=0;i<n;i++) {
        if(match(i)) ans++;
        l[i] = ans;
    }
    ans = 0;
    for(long long i=n-1;i>=0;i--) {
        if(match(i)) ans++;
        r[i] = ans;
    }
    long long res = ans;
    for(long long i=0;i<n;i++) {
        if(i>0) {
            // a[i] == a[i-1]
            ans = 0;
            if(i>1) ans += l[i-2];
            // cout<<i<<" "<<ans<<endl;
            if(i+2<n) {
                ans+=r[i+2];
                // cout<<i<<" "<<ans<<endl;
                if(valid(a[i-1], a[i+2], a[i+1])) ans++;
                // cout<<i<<" "<<ans<<endl;
            }
            // cout<<i<<" "<<ans<<endl;
            res = min(res, ans);
        }
        if(i<n-1) {
            // a[i] == a[i+1]
            ans = 0;
            if(i>1) {
                ans += l[i-2];
                if(valid(a[i-2], a[i+1], a[i-1])) ans++;
            }
            if(i+2<n) ans += r[i+2];
            res = min(res, ans);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(long long i=0;i<n;i++) cin>>a[i];
        cout<<solve()<<endl;
    }
    return 0;
}