#include <iostream>

using namespace std;

int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) {
            cout<<9<<endl;
        } else if(n==2) {
            cout<<98<<endl;
        } else {
            cout<<98;
            for(long i=3;i<=n;i++) {
                cout<<((i+6)%10);
            }
            cout<<endl;
        }
    }
    return 0;
}