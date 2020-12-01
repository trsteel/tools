#include <iostream>

using namespace std;

int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) cout<<0<<endl;
        else if(n==2) cout<<1<<endl;
        else if(n==3) cout<<2<<endl;
        else cout<<((n&1)?3:2)<<endl;
    }
    return 0;
}