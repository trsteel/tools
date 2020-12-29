#include <iostream>

using namespace std;
const long maxn = 200001;
long long t, n, a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        long long res = 0;
        for(int i=n-2;i>=0;i--) {
            res += max(0LL, a[i]-a[i+1]);
        }
        cout<<res<<endl;
    }
    return 0;
}