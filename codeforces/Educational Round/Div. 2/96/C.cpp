#include <iostream>

using namespace std;

int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==2) {
            cout<<2<<endl;
            cout<<1<<" "<<2<<endl;
        } else {
            cout<<2<<endl;
            cout<<(n-2)<<" "<<n<<endl;
            cout<<(n-1)<<" "<<(n-1)<<endl;
            for(int i=n-3;i>=1;i--) {
                cout<<i<<" "<<(i+2)<<endl;
            }
        }
    }
    return 0;
}