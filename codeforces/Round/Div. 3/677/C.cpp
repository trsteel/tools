#include <iostream>

using namespace std;

int main() {
    long t, n, a[300001];
    cin>>t;
    while(t--) {
        cin>>n;
        long ma = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i]; ma = max(ma, a[i]);
        }
        long res = -1;
        for(int i=0;i<n;i++) if(a[i]==ma) {
            if((i>0 && a[i-1] < a[i]) || (i<n-1 && a[i+1]<a[i])) {
                res = i; break;
            }
        }
        if(res != -1) res++;
        cout<<res<<endl;
    }
    return 0;
}
