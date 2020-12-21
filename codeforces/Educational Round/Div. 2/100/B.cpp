#include <iostream>
using namespace std;

long long cal(long long a) {
    long long ans = 1;
    while(ans*2<=a) ans <<= 1;
    return ans;
}

int main(){
    long long t, n, a[51];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) {
            cout<<cal(a[i])<<" ";
        }
        cout<<endl;
    }
    return 0;
}