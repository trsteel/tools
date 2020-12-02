#include <iostream>

using namespace std;

int main() {
    long t, n, a[51];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        int l = 0, r = n-1;
        while(l < n && a[l]==0) l++;
        while(r >= 0 && a[r]==0) r--;
        long res = 0;
        for(int i=l;i<=r;i++) if(a[i]==0){
            res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
