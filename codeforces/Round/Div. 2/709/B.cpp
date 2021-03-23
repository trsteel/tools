#include <iostream>

using namespace std;

const long maxn = 1e5 + 1;
long t, n, a[maxn];

bool all_eq_d() {
    for(int i=1;i<n-1;i++) {
        if(a[i-1]+a[i+1]!=2*a[i]) return false;
    }
    return true;
}

void solve() {
    if(n==1 || (all_eq_d() && a[0] <= a[1])) {
        cout<<0<<endl;
        return;
    }
    long m = -1, c = -1;
    for(int i=1;i<n;i++) {
        if(a[i-1]==a[i]) {
            cout<<-1<<endl;
            return;
        }
        if(a[i-1]<a[i]) {
            c = a[i]-a[i-1]; break;
        }
    }
    if(c==-1) {
        cout<<(all_eq_d()?0:-1)<<endl;
        return;
    }
    long ma = a[0];
    for(int i=1;i<n;i++) {
        ma = max(ma, a[i]);
        if(a[i-1]>a[i]) {
            long d = a[i-1]+c-a[i];
            if(m==-1) m = d;
            if(m!=d) {
                cout<<-1<<endl;
                return;
            }
        } else if(a[i]-a[i-1]!=c) {
            cout<<-1<<endl;
            return;
        }
    }
    if(m <= ma) {
        cout<<-1<<endl;
        return;
    }
    cout<<m<<" "<<c<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        solve();
    }
    return 0;
}