#include <iostream>

using namespace std;
const long maxn = 200005;
long long t, n, a[maxn], b[maxn];

long long solve() {
    long long res = 0;
    for(int i=n;i>0;i--) {
        b[i] = a[i];
        if(a[i]+i<=n) b[i]+=b[a[i]+i];
        res = max(res, b[i]);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i]; b[i] = 0;
        }
        cout<<solve()<<endl;
    }
    return 0;
}