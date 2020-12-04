#include <iostream>

using namespace std;

int main(){
    long t, n, k, a[1001];
    cin>>t;
    while(t--) {
        cin>>n>>k;
        long idx = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            if(a[i] < a[idx]) idx = i;
        }
        long res = 0;
        for(int i=0;i<n;i++) if(i!=idx) {
            res += (k-a[i])/a[idx];
        }
        cout<<res<<endl;
    }
    return 0;
}