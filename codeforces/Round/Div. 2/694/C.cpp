#include <iostream>
#include <algorithm>
using namespace std;
const long maxn = 300001;
long t, n, m, k[maxn], c[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>k[i];
        for(int i=0;i<m;i++) cin>>c[i];
        sort(k, k+n);
        long long res = 0, i;
        for(i=0;i<m&&i<n;i++) {
            // cout<<i<<" "<<k[n-1-i]<<endl;
            if(i+1 >= k[n-1-i]) break;
            res += c[i];
        }
        while(i++<n) res+=c[k[n-i]-1];
        cout<<res<<endl;
    }
    return 0;
}