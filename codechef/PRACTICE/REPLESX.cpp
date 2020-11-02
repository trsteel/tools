#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n, x, p, k, num;
    cin>>t;
    while (t--) {
        cin>>n>>x>>p>>k;
        int l = 0, e = 0, r = 0, ans = 0;
        for(int i=0;i<n;i++) {
            cin>>num;
            if(num < x) l++;
            else if(num>x) r++;
            else e++;
        }
        if(l<p && l+e>=p) { cout<<0<<endl; continue;}
        if(l+e<p) {
            ans = k>=p ? (p-l-e) : -1;
        } else if(l>=p) {
            ans = k<=p ? (l+1-p) : -1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
