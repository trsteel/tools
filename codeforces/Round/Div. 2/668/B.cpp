#include <iostream>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    long long t, n, a[100001];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        long long res = 0, ans = 0;
        for(int i=0;i<n;) {
            while(i<n && a[i]>=0) {
                ans += a[i++];
            }
            while(i<n && a[i]<=0) {
                ans += a[i++];
            }
            if(ans < 0) {res -= ans; ans = 0;}
            // cout<<i<<" "<<ans<<" "<<res<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}