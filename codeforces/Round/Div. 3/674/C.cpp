#include <iostream>

using namespace std;

int main() {
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) {cout<<0<<endl; continue;}
        long res = n;
        for(long i=1;i*i<=n;i++) {
            res = min(res, i+(n-i+i-1)/i-1);
        }
        cout<<res<<endl;
    }
    return 0;
}
