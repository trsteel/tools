#include <iostream>
#include <algorithm>
using namespace std;
const long maxn = 200005;
long long t, n, a[maxn];

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        long long alice = 0, bob = 0;
        for(int j=1;j<=n;j++) {
            if(j&1) {
                if(a[n-j]%2==0) alice+=a[n-j];
            } else {
                if(a[n-j]%2==1) bob+=a[n-j];
            }
        }
        if(alice==bob) {
            cout<<"Tie"<<endl;
        } else if(alice>bob) {
            cout<<"Alice"<<endl;
        } else {
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}