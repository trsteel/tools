
#include <iostream>

using namespace std;

int main(){
    long t, s, a, b, c; cin>>t;
    while(t--) {
        cin>>s>>a>>b>>c;
        if(a+b+c<=s) cout<<1<<endl;
        else if(a+b<=s||b+c<=s) cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}