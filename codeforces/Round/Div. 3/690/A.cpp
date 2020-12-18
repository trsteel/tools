#include <iostream>

using namespace std;

int main(){
    long t, n, a[301];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        long l = 0, r = n-1;
        while(l <= r) {
            cout<<a[l++]<<" ";
            if(l > r) break;
            cout<<a[r--]<<" ";
        }
        cout<<endl;
    }
    return 0;
}